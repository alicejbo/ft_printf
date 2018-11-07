/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 23:41:40 by abossard          #+#    #+#             */
/*   Updated: 2018/11/07 05:35:26 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_a(t_params *par)
{
	unsigned char	baba;
	int				i;

	i = -1;
	baba = '%';
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
			par->str[i] = (par->flags[3] == 1) ? '0' : ' ';
		par->str[i] = baba;
		par->str[i + 1] = '\0';
	}
	par->size_str = (par->width == -1) ? 1 : par->width;
}

void	direction2(t_infos *p, t_params *par)
{
	int		*flag_n;

//	ft_putstr("k\n");
	if (par->type == 'p')
	{
//		if (par->w_arg == NULL)
//			par->str = ft_strdup("0x0");
//		else
		{
			par->flags[2] = 1;
			par->length = 3;
			flag_x(par);
		}
	}
//	ft_putstr("l\n");
	if (par->type == 'n')
	{
		flag_n = (int*)par->w_arg;
		*flag_n = p->size_buf;
		par->str = ft_strdup("\0");
	}
//	ft_putstr("m\n");
	if (par->type == '\0')
		par->str = ft_strdup("\0");
//	ft_putstr("n\n");
}

void	direction1(t_infos *p, t_params *par)
{
	par->str = "\0";
//	ft_putstr("a\n");
	if (par->type == 'i')
		flag_i(par);
//	ft_putstr("b\n");
	if (par->type == 'o')
		flag_o(par);
//	ft_putstr("c\n");
	if (par->type == 'u')
		flag_u(par);
//	ft_putstr("d\n");
	if (par->type == 'x' || par->type == 'X')
		flag_x(par);
//	ft_putstr("e\n");
	if (par->type == 'c' && par->length != 3)
		flag_c(p, par);
//	ft_putstr("f\n");
	if (par->type == 's' && par->length != 3)
		flag_s(par);
//	ft_putstr("g\n");
	if (par->type == 'C' || (par->type == 'c' && par->length == 3))
		big_c(p, par, -1);
//	ft_putstr("h\n");
	if (par->type == 'a')
		flag_a(par);
//	write(FD, "yo\n", 3);
//	ft_putstr("i\n");
	if (par->type == 'S' || (par->type == 's' && par->length == 3))
		big_s(p, par, -1, 0);
//	ft_putstr("j\n");
	direction2(p, par);
	p->size_buf = p->size_buf + ft_strlen(par->str);
}
