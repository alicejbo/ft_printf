/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:29:48 by abossard          #+#    #+#             */
/*   Updated: 2018/12/31 19:47:30 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeroes_f(t_params *par, char *baba, int size_nb	)
{
	int i;

	i = 0;
	if (baba[0] == '-' && (par->flags[0] == 0 && par->flags[4] == 0))
		size_nb--;
	while (i < (par->size_str - size_nb) || ((par->flags[0] == 1
					|| par->flags[4] == 1) && i <= (par->size_str - size_nb)))
	{
		par->str[i] = '0';
		i++;
	}
	if (baba[0] == '-')
	{
		par->str[0] = '-';
		baba++;
	}
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (par->str[0] >= '0' && par->str[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
}

void	ft_justify_f(t_params *par, char *baba, int size_nb)
{
	int		i;

	i = size_nb;
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		i++;
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		i++;
	}
	par->str[i] = '\0';
}

void	flag_f2(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[1] == 1)
		ft_justify_f(par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes_f(par, baba, size_nb);
	else if (par->flags[0] == 1 || par->flags[4] == 1)
		ft_plus_sign_f(par, baba, size_nb);
	else
	{
		//	if ((int)par->w_arg == 0 && par->prec == 0)
		//		size_nb--;
		//	if (par->prec == size_nb && baba[0] == '-')
		//		size_nb++;
		while (i < (par->size_str - size_nb))
		{
			par->str[i] = ' ';
			i++;
		}
		ft_strcat(par->str, baba);
	}
}

char	*ft_arrondi(t_params *par, char *baba, int j)
{
	char	c;

	c = baba[j];
	baba[j] = '\0';
	if (c >= '5')
	{
		while (baba[--j] == '9')
			baba[j] = '0';
		if (baba[j] != '.')
			baba[j] = baba[j] + 1;
		else
		{
			--j;
			baba[j] = baba[j] + 1;
		}
	}
	if (baba[ft_strlen(baba) - 1] == '.' || (ft_strlen(baba) == 2 
				&& (int)par->w_arg == 0))
	{
		while (--j >= 0 && baba[j] != '.')
			baba[j] = '0';
	}
	return (baba);
}

char	*rempli_f(t_params *par, char *baba, int size_nb)
{
	baba = ft_arrondi(par, baba, size_nb);
	if (par->size_str > size_nb || ((par->flags[0] != 1 && par->flags[4] != 1)
				&& par->size_str == (size_nb + 1)))
		flag_f2(par, baba, size_nb);
	else
	{
		if (par->flags[0] == 1 || par->flags[4] == 1)
		{
			if (baba[0] != '-')
				par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
		}
		ft_strcat(par->str, baba);
	}
	return (baba);
}
