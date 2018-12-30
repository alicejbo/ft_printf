/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:51:09 by abossard          #+#    #+#             */
/*   Updated: 2018/12/30 17:52:01 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_nb(char *baba, t_params *par, int size_nb)
{
	int i;

	i = 0;
	while (baba[i++] != '.')
	{
		size_nb++;
		printf("nb = %d\n", size_nb);
	}
	if ((ft_strlen(baba) - (size_nb + 1)) > 6 && par->prec == -1)
		size_nb = size_nb + 6;
	else if (par->prec > 0)
		size_nb = size_nb + par->prec + 1;
	return (size_nb);
}

char	*ft_deci(int i, long double nb, int tmp, char *baba)
{
	while (nb > 0)
	{
		nb = nb * 10;
		tmp = nb / 1;
		nb = nb - tmp;
		baba[i] = ft_itoa(tmp)[0];
		i++;
	}
	return (baba);
}

char	*ft_nbr_f(long double str_b, char *baba)
{
	int				i;
	long double		nb;
	long double		tmp;

	i = 0;
	if (str_b < 0)
	{
		baba[i++] = '-';
		nb = -str_b;
	}
	else
		nb = str_b;
	if (nb < 1)
		baba[i++] = '0';
	while (nb >= 1)
	{
		tmp = nb / 1;
		printf("nb = %Lf\n", nb);
		nb = nb - tmp;
		baba = ft_itoa(tmp);
		i = i + ft_strlen(ft_itoa(tmp));
	}
	baba[i++] = '.';
	baba = ft_deci(i, nb, tmp, baba);
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
	int		size_nb;

	size_nb = 0;
	baba = length_f(par);
//	par->size_str = ft_strlen(baba);
//	size_nb = ft_size_nb(baba, par, size_nb);
//	printf("size_nb = %d\n", size_nb);
	par->str = baba;
	//	printf("baba = %s\n", baba);
}
