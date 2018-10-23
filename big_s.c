/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:08:39 by abossard          #+#    #+#             */
/*   Updated: 2018/10/23 16:10:15 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wstring_s(wchar_t wstr, char *str, int i, int size)
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

void	big_s(t_infos *p, t_params *par, int j, int size)
{
	wchar_t		*baba;
	int			i;

	baba = (wchar_t *)par->w_arg;
	while (baba[++j] != '\0')
		size = size + ft_val_wchar(baba[j]);
	j = -1;
	par->str = ft_memalloc(size + par->width);
	if (par->flags[1] == 1)
	{
		i = 0;
		while (baba[++j] != '\0')
			i = wstring_s(baba[j], par->str, i, 0);
		while (++i <= par->width)
			par->str[i - 1] = ' ';
	}
	else
	{
		i = -1;
		while (++i < par->width - size)
			par->str[i] = ' ';
		while (baba[++j] != '\0')
			i = wstring_s(baba[j], par->str, i, 0);
	}
}
