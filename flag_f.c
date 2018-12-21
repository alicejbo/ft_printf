/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:51:09 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 15:10:36 by abossard         ###   ########.fr       */
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
	printf("nb = %Lf\n", str_b);
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
	double			nb_d;
	long double		nb_ld;
//	float			*nb_f;

//	printf("arg = %d\n", *par->w_arg);
	baba = ft_memalloc(1500);
	if (par->length == 0 || par->length == 9)
	{
		nb_d = *(double *)par->w_arg;
//		printf("double %f\n", nb_d);
		baba = ft_nbr_f(nb_d, baba);
	}
	if (par->length == 7 || par->length == 10)
	{
		nb_ld = *(long double *)par->w_arg;
//		printf("l double %Lf\n", nb_ld);
		baba = ft_nbr_f(nb_ld, baba);
	}
	if (par->length == 8)
	{
		nb_ld = *(float *)par->w_arg;
//		printf("float %Lf\n", nb_ld);
		baba = ft_nbr_f(nb_ld, baba);
	}
	return (baba);
}

void	flag_f(t_params *par)
{
	char	*baba;
//	int		size_nb;

	par->str = ft_strdup("abossard");
	baba = length_f(par);
//	printf("baba = %s\n", baba);
}
