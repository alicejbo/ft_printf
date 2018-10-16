/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2018/10/16 13:11:56 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeroes_u(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	while (i < (par->size_str - size_nb))
	{
		par->str[i] = '0';
		i++;
	}
	ft_strcat(par->str, baba);
}

void	ft_justify_u(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;

	i = size_nb;
	ft_strcat(par->str, baba);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		i++;
	}
}

void	flag_u2(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[1] == 1)
		ft_justify_u(p, par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes_u(p, par, baba, size_nb);
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
