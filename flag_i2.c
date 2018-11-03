/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2018/11/03 18:38:24 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_sign(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	while (i < (par->size_str - size_nb))
	{
		par->str[i] = ' ';
		i++;
	}
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[i] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
}

void	ft_zeroes(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	while (i < (par->size_str - size_nb) || ((par->flags[0] == 1 
					|| par->flags[4] == 1) && i <= (par->size_str - size_nb)))
	{
		par->str[i] = '0';
		i++;
	}
	if (baba[0] == '-')
	{
		par->str[0] = '-';
		baba[0] = '0';
	}
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
}

void	ft_justify(t_params *par, char *baba, int size_nb)
{
	int i;

	i = size_nb + 1;
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		i++;
	}
}

void	flag_i2(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[1] == 1)
		ft_justify(par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes(par, baba, size_nb);
	else if (par->flags[0] == 1 || par->flags[4] == 1)
		ft_plus_sign(par, baba, size_nb);
	else
	{
		while (i < (par->size_str - size_nb))
		{
			par->str[i] = ' ';
			i++;
		}
		ft_strcat(par->str, baba);
	}
}
