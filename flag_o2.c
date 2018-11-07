/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2018/11/07 00:35:50 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeroes_o(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[2] == 1 && (int)par->w_arg != 0)
		size_nb--;
	while (i < (par->size_str - size_nb))
	{
		par->str[i] = '0';
		i++;
	}
	ft_strcat(par->str, baba);
}

void	ft_justify_o(t_params *par, char *baba, int size_nb)
{
	int i;

	if (par->flags[2] == 1 && (int)par->w_arg != 0)
		par->str[0] = '0';
	i = size_nb;
	ft_strcat(par->str, baba);
//	printf("baba o = %s\n", par->str);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		i++;
	}
//	printf("baba o = %s\n", par->str);
}

void	flag_o2(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[1] == 1)
		ft_justify_o(par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes_o(par, baba, size_nb);
	else
	{
		if ((int)par->w_arg == 0)
			size_nb--;
		while (i < (par->size_str - size_nb))
		{
			par->str[i] = ' ';
			i++;
		}
		if (par->flags[2] == 1 && (int)par->w_arg != 0)
			par->str[i] = '0';
		ft_strcat(par->str, baba);
	}
}
