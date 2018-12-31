/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:51:09 by abossard          #+#    #+#             */
/*   Updated: 2018/12/31 21:01:59 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_nb(t_params *par, char *baba, int size_nb)
{
	int				i;

	i = 0;
	while (baba[i++] != '.')
		size_nb++;
	if (((ft_strlen(baba) - (size_nb + 1)) > 6 || par->w_arg == 0)
			&& par->prec == -1)
		size_nb = size_nb + 7;
	else if (par->prec > 0 || (par->prec == 0 && par->flags[1] == 1))
		size_nb = size_nb + par->prec + 1;
	return (size_nb);
}

char	*ft_deci(int i, long double nb, char *baba)
{
	int				tmp;
	char			*baba2;

	while (nb >= 1)
	{
		tmp = nb / 1;
		nb = nb - tmp;
		baba2 = ft_itoa(tmp);
		baba = ft_strcpy(baba, baba2);
		i = i + ft_strlen(baba2);
		free(baba2);
	}
	baba[i++] = '.';
	while (nb > 0)
	{
		nb = nb * 10;
		tmp = nb / 1;
		nb = nb - tmp;
		baba2 = ft_itoa(tmp);
		baba[i] = baba2[0];
		free(baba2);
		i++;
	}
	return (baba);
}

char	*ft_nbr_f(long double str_b, char *baba)
{
	int				i;
	long double		nb;

	i = 0;
	if (str_b < 0)
	{
		baba[i++] = '-';
		nb = -str_b;
	}
	else
		nb = str_b;
	if (nb < 1 || nb == 0)
		baba[i++] = '0';
	baba = ft_deci(i, nb, baba);
	return (baba);
}

char	*length_f(t_params *par)
{
	char			*baba;

	//	printf("arg = %f\n", par->f);
	baba = ft_memalloc(1500);
	if (par->length == 0 || par->length == 9)
		baba = ft_nbr_f(par->d, baba);
	if (par->length == 7 || par->length == 10)
		baba = ft_nbr_f(par->ld, baba);
	if (par->length == 8)
		baba = ft_nbr_f(par->f, baba);
	return (baba);
}

void	flag_f(t_params *par)
{
	char	*baba;
	int		size_nb;

	size_nb = 0;
	baba = length_f(par);
	size_nb = ft_size_nb(par, baba, size_nb);
	par->size_str = size_nb;
	if (par->flags[0] == 1 || par->flags[4] == 1)
		if (baba[0] != '-')
			par->size_str++;
	if (par->size_str < par->width)
		par->size_str = par->width;
	printf("baba = %s\n", baba);
	par->str = ft_memalloc(par->size_str);
	baba = rempli_f(par, baba, size_nb);
	ft_strdel(&baba);
}
