/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:51:09 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 19:09:53 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_nbr_f(long double str_b, char *baba)
{
	int				i;
	long double		nb;
	int				tmp;

	i = 0;
	if (str_b < 0)
	{
		baba[0] = '-';
		nb = str_b;
		baba++;
	}
	else
		nb = str_b;
//	printf("nb = %Lf\n", str_b);
	while (nb >= 1)
	{
		tmp = nb / 1;
		nb = nb - tmp;
		baba[i] = ft_itoa(tmp)[0];
		i++;
	}
	baba[i++] = '.';
//	printf("baba 1 = %s\n", baba);
	while (nb > 0)
	{
		nb = nb * 10;
		tmp = nb / 1;
		nb = nb - tmp;
		baba[i] = ft_itoa(tmp)[0];
		i++;
	}
//	printf("baba 2 = %s\n", baba);
	return (baba);
}

char	*length_f(t_params *par)
{
	char			*baba;

//	printf("arg = %f\n", par->f);
	baba = ft_memalloc(1500);
	if (par->length == 0 || par->length == 9)
	{
		baba = ft_nbr_f(par->d, baba);
	}
	if (par->length == 7 || par->length == 10)
	{
//		printf("l double %Lf\n", nb_ld);
		baba = ft_nbr_f(par->ld, baba);
	}
	if (par->length == 8)
	{
//		printf("float %Lf\n", nb_ld);
		baba = ft_nbr_f(par->f, baba);
	}
	return (baba);
}

void	flag_f(t_params *par)
{
	char	*baba;
//	int		size_nb;

	baba = length_f(par);
	par->str = baba;
//	printf("baba = %s\n", baba);
}
