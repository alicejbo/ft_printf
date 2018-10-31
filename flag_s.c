/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/10/31 17:27:14 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_s2(t_infos *p, t_params *par, char *baba)
{
	int				i;

	par->str = ft_memalloc(par->width);
	if (par->flags[1] == 1)
	{
		ft_putstr("caca4\n");
		i = par->size_str;
		par->str = ft_strcpy(par->str, baba);
		while (i < par->width)
		{
			par->str[i] = ' ';
			ft_putstr("caca5\n");
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
			ft_putstr("caca6\n");
		}
		par->str = ft_strcat(par->str, baba);
	}
}

void	flag_s(t_infos *p, t_params *par)
{
	char		*baba;

	if ((char *)par->w_arg == NULL)
		baba = ft_strdup("(null)\0");
	else
	{
		ft_putstr("caca\n");
		baba = (char *)ft_memalloc(ft_strlen((char *)par->w_arg) + 1);
		baba = ft_strcpy(baba, (char *)par->w_arg);
	}
	par->size_str = ft_strlen(baba);
	if (par->prec < par->size_str && par->prec != -1)
	{
		ft_putstr("caca2\n");
		par->size_str = par->prec;
		baba[par->prec] = '\0';
	}
	if (par->size_str < par->width)
		flag_s2(p, par, baba);
	else
	{
		ft_putstr("caca3\n");
		ft_putnbr(par->size_str);
		ft_putchar('\n');
		ft_putstr(baba);
		ft_putchar('\n');
		par->str = ft_memalloc(par->size_str);
		par->str = ft_strcpy(par->str, baba);
	}
	ft_strdel(&baba);
}
