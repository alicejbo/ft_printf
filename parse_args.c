/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:26:31 by abossard          #+#    #+#             */
/*   Updated: 2018/07/21 23:57:50 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_args3(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	if (str[K] == 'h' && str[K + 1] == 'h')
	{
		par->length = 1;
		K++;
	}
	if (str[K] == 'h')
		par->length = 2;
	if (str[K] == 'l')
		par->length = 3;
	if (str[K] == 'l' && str[K + 1] == 'l')
	{
		par->length = 4;
		K++;
	}
	if (str[K] == 'L')
		par->length = 5;
	if (str[K] == 'z')
		par->length = 6;
	K++;
	parse_args4(str, p, par);
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
	K++;
	parse_args3(str, p, par);
}

void	parse_args1(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	K = 1;
	if (str[K] == '+' || str[K] == '-' || str[K] == '#' || str[K] == '0'
			|| str[K] == ' ')
	{
		while (str[K] == '+' || str[K] == '-' || str[K] == '#' || str[K] ==
				'0' || str[K] == ' ')
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

