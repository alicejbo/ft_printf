/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:26:31 by abossard          #+#    #+#             */
/*   Updated: 2018/07/19 20:12:49 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_args1(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	K = 1;
	if (str[K] == '+' && str[K] == '-' && str[K] == '#' && str[K] == '0'
			&& str[K] == ' ')
	{
		while (str[K] == '+' && str[K] == '-' && str[K] == '#' && str[K] ==
				'0' && str[K] == ' ')
		{
			if (str[K] == '+')
				par->flags[0] = 1;
			if (str[K] == '-')
				par->flags[1] = 1;
			if (str[K] == '#')
				par->flags[2] = 1;
			if (str[K] == '0')
				par->flags[3] = 1;
			if (str[K] == ' ')
				par->flags[4] = 1;
			K++;
		}
	}
	parse_args2(str, p, par);
}

void	parse_args2(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	if (str[K] == '.')
	{
		L = K;
		while (str[K] >= '0' && str[K] <= '9')
			K++;
		par->prec = ft_atoi(ft_strsub(str, L, (K - L)));
	}
}
