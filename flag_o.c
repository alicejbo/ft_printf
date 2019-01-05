/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 15:22:16 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_o(t_params *par, char *baba)
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
		baba2 = ft_memalloc(par->size_str + 10);
		while (i < diff)
		{
			baba2[i] = '0';
			i++;
		}
		ft_strcpy(baba2 + i, baba);
	}
	if (par->prec > (int)ft_strlen(baba) && par->flags[2] == 1)
		par->flags[2] = 0;
	return (baba2);
}

char	*rempli_o(t_params *par, char *baba, int size_nb)
{
	int		i;
	char	*nb_preci;

	i = 0;
	if ((size_t)par->prec > ft_strlen(baba) || (par->prec == 0
			&& (int)par->w_arg == 0))
	{
		nb_preci = ft_strdup(baba);
		ft_strdel(&baba);
		baba = prec_o(par, nb_preci);
		ft_strdel(&nb_preci);
	}
	if (par->size_str > size_nb)
		flag_o2(par, baba, size_nb);
	else if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->prec == 0))
	{
		par->str[0] = '0';
		ft_strcat(par->str + 1, baba);
	}
	else
		ft_strcat(par->str, baba);
	return (baba);
}

char	*length_o(t_params *par)
{
	char	*baba;

	if (par->length == 0)
		baba = ft_itoa_base_ll((unsigned int)par->w_arg, 8);
	if (par->length == 1)
		baba = ft_itoa_base_ll((unsigned short int)par->w_arg, 8);
	if (par->length == 2)
		baba = ft_itoa_base_ll((unsigned char)par->w_arg, 8);
	if (par->length == 3)
		baba = ft_itoa_base_ll((unsigned long int)par->w_arg, 8);
	if (par->length == 4)
		baba = ft_itoa_base_ll((unsigned long long int)par->w_arg, 8);
	if (par->length == 5)
		baba = ft_itoa_base_ll((uintmax_t)par->w_arg, 8);
	if (par->length == 6)
		baba = ft_itoa_base_ll((ssize_t)par->w_arg, 8);
	return (baba);
}

void	flag_o(t_params *par)
{
	char	*baba;
	int		size_nb;

	baba = length_o(par);
	par->size_str = ft_strlen(baba);
	size_nb = ft_strlen(baba);
	if (par->flags[2] == 1 && ((int)par->w_arg != 0 || (par->prec == 0
					&& (int)par->w_arg == 0)))
		size_nb++;
	if (par->size_str < par->width)
		par->size_str = par->width;
	if (size_nb < par->prec)
		size_nb = par->prec;
	if (size_nb > par->size_str)
		par->size_str = size_nb;
	par->str = ft_memalloc(par->size_str + 10);
	baba = rempli_o(par, baba, size_nb);
	ft_strdel(&baba);
}
