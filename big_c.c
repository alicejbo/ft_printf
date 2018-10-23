/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:22:59 by abossard          #+#    #+#             */
/*   Updated: 2018/10/23 16:14:23 by abossard         ###   ########.fr       */
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

void	big_c(t_infos *p, t_params *par)
{
	wchar_t			baba;
	int				i;

	i = -1;
	baba = (wchar_t)par->w_arg;
	par->str = ft_memalloc(ft_val_wchar((wchar_t)par->w_arg) + 2);
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
