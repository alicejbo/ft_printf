/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2018/10/02 13:18:56 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_sign(t_infos *p, t_params *par, char *baba, int size_nb)
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

void	ft_zeroes(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	while (i < (par->size_str - size_nb) || ((par->flags[0] == 1 
					|| par->flags[4] == 1) && i <= (par->size_str - size_nb)))
	{
		par->str[i] = '0';
		i++;
	}
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	printf("flag str z = %s\n", par->str);
	ft_strcat(par->str, baba);
}

void	ft_justify(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;
	int new_size;

	i = size_nb;
	if (par->flags[0] == 1 || par->flags[4] == 1)
	{
		if (baba[0] >= '0' && baba[0] <= '9')
			par->str[0] = (par->flags[0] == 1) ? '+' : ' ';
	}
	printf("baba justif %s\n", par->str);
	ft_strcat(par->str, baba);
	printf("baba justif 2 %s\n", par->str);
	while (i < par->size_str)
	{
		par->str[i] = ' ';
		printf("a\n");
		i++;
	}
	printf("baba justif 3 %s\n", par->str);
}

void	flag_i2(t_infos *p, t_params *par, char *baba, int size_nb)
{
	int i;

	i = 0;
	if (par->flags[1] == 1)
		ft_justify(p, par, baba, size_nb);
	else if (par->flags[3] == 1)
		ft_zeroes(p, par, baba, size_nb);
	else if (par->flags[0] == 1 || par->flags[4] == 1)
		ft_plus_sign(p, par, baba, size_nb);
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
