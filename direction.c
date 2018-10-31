/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 23:41:40 by abossard          #+#    #+#             */
/*   Updated: 2018/10/31 17:31:47 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	direction2(t_infos *p, t_params *par)
{
	int		*flag_n;

	if (par->type == 'n')
	{
		flag_n = (int*)par->w_arg;
		*flag_n = p->size_buf;
		par->str = ft_strdup("\0");
	}
	if (par->type == '\0')
		par->str = ft_strdup("\0");
}

void	direction1(t_infos *p, t_params *par)
{
	par->str = "\0";
	if (par->type == 'i')
		flag_i(p, par);
	if (par->type == 'o')
		flag_o(p, par);
	if (par->type == 'u')
		flag_u(p, par);
	if (par->type == 'x' || par->type == 'X')
		flag_x(p, par);
	if (par->type == 'p')
	{
		par->flags[2] = 1;
		flag_x(p, par);
	}
	if (par->type == 'c')
		flag_c(p, par);
	if (par->type == 's')
		flag_s(p, par);
	if (par->type == 'C')
		big_c(p, par, -1);
	if (par->type == 'S')
		big_s(p, par, -1, 0);
	direction2(p, par);
	p->size_buf = p->size_buf + ft_strlen(par->str);
}
