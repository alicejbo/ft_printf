/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/10/17 16:00:12 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_c(t_infos *p, t_params *par)
{
	unsigned char	baba;
	int		i;

	i = -1;
	baba = (unsigned char)par->w_arg;
	par->str = ft_memalloc(par->width + 2);
	if (par->flags[1] == 1)
	{
		par->str[i + 1] = baba;
		while (++i < par->width - 1)
			par->str[i + 1] = ' ';
	}
	else
	{
		while (++i < par->width - 1)
			par->str[i] = ' ';
		par->str[i] = baba;
		par->str[i + 1] = '\0';
	}
}
