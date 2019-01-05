/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 16:41:49 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_s2(t_params *par, char *baba)
{
	int				i;

	par->str = ft_memalloc(par->width);
	if (par->flags[1] == 1)
	{
		i = par->size_str;
		par->str = ft_strcpy(par->str, baba);
		while (i < par->width)
		{
			par->str[i] = ' ';
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < par->width - par->size_str)
		{
			par->str[i] = ' ';
			i++;
		}
		par->str = ft_strcat(par->str, baba);
	}
}

void	flag_s(t_params *par)
{
	char		*baba;

	if ((char *)par->w_arg == NULL)
		baba = ft_strdup("(null)\0");
	else
	{
		baba = (char *)ft_memalloc(ft_strlen((char *)par->w_arg) + 1);
		baba = ft_strcpy(baba, (char *)par->w_arg);
	}
	par->size_str = ft_strlen(baba);
	if (par->prec < par->size_str && par->prec != -1)
	{
		par->size_str = par->prec;
		baba[par->prec] = '\0';
	}
	if (par->size_str < par->width)
		flag_s2(par, baba);
	else
	{
		par->str = ft_memalloc(par->size_str);
		par->str = ft_strcpy(par->str, baba);
	}
	ft_strdel(&baba);
}
