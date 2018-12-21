/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:22:59 by abossard          #+#    #+#             */
/*   Updated: 2018/12/06 15:19:26 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wstring(wchar_t wstr, char *str, int i, int size)
{
	size = ft_val_wchar(wstr);
	if (wstr <= 255 && MB_CUR_MAX == 1)
		str[i++] = (char)wstr;
	else if (size == 1)
		str[i++] = (char)wstr;
	else if (size == 2)
	{
		str[i++] = (wstr >> 6) + 0xc0;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	else if (size == 3)
	{
		str[i++] = (wstr >> 12) + 0xe0;
		str[i++] = ((wstr >> 6) & 0x3f) + 0x80;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	else
	{
		str[i++] = (wstr >> 18) + 0xf0;
		str[i++] = ((wstr >> 12) & 0x0f) + 0x80;
		str[i++] = ((wstr >> 6) & 0x0f) + 0x80;
		str[i++] = (wstr & 0x3f) + 0x80;
	}
	return (i);
}

void	back_zero2(t_infos *p, t_params *par)
{
	if (par->flags[1] == 1)
		p->size_buf = p->size_buf + par->width;
	else
		p->size_buf = p->size_buf + 1;
}

void	back_c_zero(t_infos *p, t_params *par)
{
	unsigned char	baba;
	int				i;

	i = -1;
	if ((unsigned char)par->w_arg == '\0')
		back_zero2(p, par);
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

void	big_c(t_infos *p, t_params *par, int i)
{
	wchar_t			baba;

	if ((unsigned char)par->w_arg == '\0')
		return (back_c_zero(p, par));
	baba = (wchar_t)par->w_arg;
	par->str = ft_memalloc(ft_val_wchar((wchar_t)par->w_arg) + 2);
	if (ft_val_wchar((wchar_t)par->w_arg) > MB_CUR_MAX)
		p->mb_cur = -1;
	else
	{
		if (par->flags[1] == 1)
		{
			i = 0;
			i = wstring(baba, par->str, i, 0);
			while (++i <= par->width)
				par->str[i - 1] = ' ';
		}
		else
		{
			while (++i < par->width - ft_val_wchar((wchar_t)par->w_arg))
				par->str[i] = ' ';
			i = wstring(baba, par->str, i, 0);
		}
	}
}
