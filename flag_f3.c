/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:57:10 by abossard          #+#    #+#             */
/*   Updated: 2018/12/30 23:24:47 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_sign_f(t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	while (i < (par->size_str - size_nb - 1))
	{
		par->str[i] = ' ';
		i++;
	}
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		//printf("str %d\n", par->si		ze_str);
		////printf("i %d\n", i);
		if ((int)par->w_arg >= 0)
			par->str[i] = (par->flags[0] == 1) ? '+' : ' ';
	}
	ft_strcat(par->str, baba);
}
