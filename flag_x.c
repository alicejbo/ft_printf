/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 20:42:39 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_x(t_params *par, char *baba)
{
	int		diff;
	int		i;
	char	*baba2;

	i = 0;
	if (par->prec == 0 && (int)par->w_arg == 0)
		baba2 = ft_strdup("\0");
	else
	{
		diff = (par->prec - ft_strlen(baba));
		baba2 = ft_memalloc(par->size_str);
		while (i < diff)
		{
			baba2[i] = '0';
			i++;
		}
		ft_strcpy(baba2 + i, baba);
	}
	return (baba2);
}

char	*rempli_x(t_params *par, char *baba, int size_nb)
{
	char	*nb_preci;

	if ((size_t)par->prec > ft_strlen(baba) || (par->prec == 0
				&& (int)par->w_arg == 0))
	{
		nb_preci = ft_strdup(baba);
		ft_strdel(&baba);
		baba = prec_x(par, nb_preci);
		ft_strdel(&nb_preci);
	}
	if (par->size_str > size_nb)
		flag_x2(par, baba, size_nb);
	else if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->type == 'p'))
	{
		par->str[0] = '0';
		par->str[1] = 'x';
		ft_strcat(par->str + 2, baba);
	}
	else
		ft_strcat(par->str, baba);
	return (baba);
}

char	*length_x(t_params *par)
{
	char	*baba;

	if (par->length == 0)
		baba = ft_itoa_base_ll((unsigned int)par->w_arg, 16);
	if (par->length == 1)
		baba = ft_itoa_base_ll((unsigned short int)par->w_arg, 16);
	if (par->length == 2)
		baba = ft_itoa_base_ll((unsigned char)par->w_arg, 16);
	if (par->length == 3)
		baba = ft_itoa_base_ll((unsigned long int)par->w_arg, 16);
	if (par->length == 4)
		baba = ft_itoa_base_ll((unsigned long long int)par->w_arg, 16);
	if (par->length == 5)
		baba = ft_itoa_base_ll((uintmax_t)par->w_arg, 16);
	if (par->length == 6)
		baba = ft_itoa_base_ll((ssize_t)par->w_arg, 16);
	return (baba);
}

void	flag_x(t_params *par)
{
	char	*baba;
	int		size_nb;

	baba = length_x(par);
	par->size_str = ft_strlen(baba);
	size_nb = ft_strlen(baba);
	if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->type == 'p'))
	{
		if (par->prec > 0 && (par->type != 'p'))
			par->width = par->width - 2;
		size_nb = size_nb + 2;
	}
	if (par->size_str < par->width)
		par->size_str = par->width;
	if (size_nb < par->prec)
		size_nb = par->prec;
	if (size_nb > par->size_str)
		par->size_str = size_nb;
	par->str = ft_memalloc(par->size_str + 4);
	baba = rempli_x(par, baba, size_nb);
	if (par->type == 'X')
		par->str = ft_str_upper(par->str);
	ft_strdel(&baba);
}
