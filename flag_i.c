/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 19:53:24 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_i(t_params *par, char *baba, int i)
{
	int		diff;
	char	*baba2;

	if (par->prec == 0 && (int)par->w_arg == 0)
		baba2 = ft_strdup("\0");
	else
	{
		diff = (par->prec - ft_strlen(baba));
		baba2 = ft_memalloc(par->size_str);
		if (baba[0] == '-')
		{
			i = 1;
			baba2[0] = '-';
			diff = diff + 2;
		}
		while (i < diff)
			baba2[i++] = '0';
		if (baba[0] == '-')
			ft_strcpy(baba2 + i, baba + 1);
		else
			ft_strcpy(baba2 + i, baba);
	}
	return (baba2);
}

void	nb_seul(t_params *par, char *baba)
{
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if ((int)par->w_arg >= 0)
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
}

char	*rempli_i(t_params *par, char *baba, int size_nb)
{
	int		i;
	char	*nb_preci;

	i = 0;
	if ((size_t)par->prec > ft_strlen(baba) || (par->prec == 0
				&& (int)par->w_arg == 0) || ((int)ft_strlen(baba) == par->prec
				&& baba[0] == '-'))
	{
		nb_preci = ft_strdup(baba);
		ft_strdel(&baba);
		baba = prec_i(par, nb_preci, 0);
		ft_strdel(&nb_preci);
	}
	if (par->size_str > size_nb)
		flag_i2(par, baba, size_nb);
	else
		nb_seul(par, baba);
	return (baba);
}

char	*length_i(t_params *par)
{
	char	*baba;

	if (par->length == 0)
		baba = ft_itoa_base((int)par->w_arg, 10);
	if (par->length == 1)
		baba = ft_itoa_base((short int)par->w_arg, 10);
	if (par->length == 2)
		baba = ft_itoa_base((signed char)par->w_arg, 10);
	if (par->length == 3)
		baba = ft_itoa_base((long int)par->w_arg, 10);
	if (par->length == 4)
		baba = ft_itoa_base((long long int)par->w_arg, 10);
	if (par->length == 5)
		baba = ft_itoa_base((uintmax_t)par->w_arg, 10);
	if (par->length == 6)
		baba = ft_itoa_base((size_t)par->w_arg, 10);
	return (baba);
}

void	flag_i(t_params *par)
{
	char	*baba;
	int		size_nb;

	baba = length_i(par);
	par->size_str = ft_strlen(baba);
	size_nb = ft_strlen(baba);
	if (par->flags[0] == 1 || par->flags[4] == 1)
		if (baba[0] != '-')
		{
			par->size_str++;
			size_nb++;
		}
	if (par->size_str < par->width)
		par->size_str = par->width;
	if (size_nb < par->prec)
		size_nb = par->prec;
	if (size_nb > par->size_str)
		par->size_str = size_nb;
	par->str = ft_memalloc(par->size_str);
	baba = rempli_i(par, baba, size_nb);
	ft_strdel(&baba);
}
