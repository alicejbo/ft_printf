/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:26:31 by abossard          #+#    #+#             */
/*   Updated: 2018/08/20 00:45:12 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	priorities(t_params *par)
{
	if (par->flags[3] == 1)
	{
		if (par->flags[1] == 1)
			par->flags[3] = 0;
		if ((par->type == 'd' || par->type == 'D' || par->type == 'i' 
				|| par->type == 'o' || par->type == 'O' || par->type == 'u'
				|| par->type == 'U' || par->type == 'x' || par->type == 'X')
				&& par->prec != -1)
			par->flags[3]= 0;
	}
	if (par->flags[0] == 1)
		if (par->flags[4] == 1)
			par->flags[4] = 0;
}

void	parse_args4(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	par->length = (str[K] == 'h')? 1 : 0;
	if (str[K] == 'h' && str[K + 1] == 'h')
	{
		par->length = 2;
		K++;
	}
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
	if (par->length != 0)
		K++;
	parse_args5(str, p, par);
}

void	parse_args3(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	if (str[K] == '.')
	{
		K++;
		par->prec = ft_atoi(str + K);
		while (str[K] >= '0' && str[K] <= '9')
			K++;
	}
	parse_args4(str, p, par);
}

void	parse_args2(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	if (str[K] >= '0' && str[K] <= '9')
	{
		par->width = ft_atoi(str + K);
		while (str[K] >= '0' && str[K] <= '9')
			K++;
	}
	parse_args3(str, p, par);
}

void	parse_args1(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	K = 1;
	if (str[K] == '+' || str[K] == '-' || str[K] == '#' || str[K] == '0'
			|| str[K] == ' ')
	{
		while (str[K] == '+' || str[K] == '-' || str[K] == '#'
			|| (str[K] =='0' && par->flags[3] != 1) || str[K] == ' ')
		{
			if (str[K] == '+')
				par->flags[0] = 1;
			if (str[K] == '-')
				par->flags[1] = 1;
			if (str[K] == '#')
				par->flags[2] = 1;
			if (str[K] == ' ')
				par->flags[4] = 1;
			if (str[K] == '0')
				par->flags[3] = 1;
			K++;
		}
	}
	parse_args2(str, p, par);
}
