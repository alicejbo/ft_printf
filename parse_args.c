/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:26:31 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 18:43:19 by abossard         ###   ########.fr       */
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
	if (par->prec > 0)
		par->flags[3] = 0;
}

void	parse_args4(char *str, t_infos *p, t_params *par)
{
	par->str = str;
	par->length = (str[K] == 'h') ? 1 : par->length;
	if (str[K] == 'h' && str[K + 1] == 'h')
	{
		par->length = 2;
		K++;
	}
	par->length = (str[K] == 'l') ? 3 : par->length;
	if (str[K] == 'l' && str[K + 1] == 'l')
	{
		par->length = 4;
		K++;
	}
	par->length = (str[K] == 'j') ? 5 : par->length;
	par->length = (str[K] == 'z') ? 6 : par->length;
	par->length = (str[K] == 'L') ? 7 : par->length;
	par->length = (str[K] == 'H') ? 8 : par->length;
	par->length = (str[K] == 'Q') ? 0 : par->length;
	if (str[K] == 'Q' && str[K + 1] == 'Q')
	{
		par->length = 10;
		K++;
	}
	K = (par->length != 0) ? K + 1 : K;
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
			|| str[K] =='0' || str[K] == ' ')
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
