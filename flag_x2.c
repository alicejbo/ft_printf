/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 15:32:18 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeroes_x(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->type == 'p'))
	{
		par->str[i] = '0';
		par->str[++i] = 'x';
		size_nb = size_nb - 2;
		i++;
	}
	while (i < (par->size_str - size_nb))
	{
		par->str[i] = '0';
		i++;
	}
	ft_strcat(par->str, baba);
}

void	ft_justify_x(t_params *par, char *baba, int size_nb)
{
	int i;

	if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->type == 'p'))
	{
		par->str[0] = '0';
		par->str[1] = 'x';
	}
	i = size_nb;
	ft_strcat(par->str, baba);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		i++;
	}
	par->str[i] = '\0';
}

void	flag_x2(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	size_nb = (par->flags[2] == 1 && ((par->prec != -1 && par->type != 'p')
				&& (int)par->w_arg == 0)) ? size_nb + 2 : size_nb;
	if (par->flags[1] == 1)
		ft_justify_x(par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes_x(par, baba, size_nb);
	else
	{
		if ((int)par->w_arg == 0 && par->type != 'p')
			size_nb--;
		if ((int)par->w_arg == 0 && par->flags[2] == 1 && par->type != 'p')
			size_nb = 0;
		while (i < (par->size_str - size_nb))
			par->str[i++] = ' ';
		if (par->flags[2] == 1 && ((int)par->w_arg != 0 || par->type == 'p'))
		{
			par->str[i++] = '0';
			par->str[i++] = 'x';
		}
		ft_strcat(par->str, baba);
	}
}
