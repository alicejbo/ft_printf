/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/11/04 18:13:43 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	back_zero(t_infos *p, t_params *par)
{
	if (par->flags[1] == 1)
		p->size_buf = p->size_buf + par->width;
	else
		p->size_buf = p->size_buf + 1;
}

void	flag_c(t_infos *p, t_params *par)
{
	unsigned char	baba;
	int				i;

	i = -1;
	if ((unsigned char)par->w_arg == '\0')
		back_zero(p, par);
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
	par->size_str = (par->width == -1) ? 1 : par->width;
}
