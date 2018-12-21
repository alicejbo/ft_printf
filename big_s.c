/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:08:39 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 17:05:10 by abossard         ###   ########.fr       */
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

void	flag2(t_params *par, char *baba2)
{
	int i;

	par->str = ft_memalloc(par->width);
	if (par->flags[1] == 1)
	{
		i = par->size_str;
		par->str = ft_strcpy(par->str, baba2);
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
		par->str = ft_strcat(par->str, baba2);
	}
}

void	nulle(t_params *par)
{
	char	*baba2;

	baba2 = ft_strdup("(null)\0");
	par->size_str = ft_strlen(baba2);
	//ft_putnbr(par->size_str);
	if (par->size_str < par->width)
		flag2(par, baba2);
	else
	{
		par->str = ft_memalloc(par->size_str);
		par->str = ft_strcpy(par->str, baba2);
	}
	ft_strdel(&baba2);
}

void	flag(t_params *par, int j, wchar_t *baba)
{
	int		i;

	i = 0;
	while (baba[++j] != '\0')
		i = wstring_s(baba[j], par->str, i, 0);
	while (++i <= par->width)
		par->str[i - 1] = ' ';
}

void	big_s(t_infos *p, t_params *par, int j, int size, int i)
{
	wchar_t		*baba;
//	int			i;

	if (par->w_arg == NULL)
		return (nulle(par));
	baba = par->w_arg;
	while (baba[++j] != '\0')
	{
		if (ft_val_wchar(baba[j]) > MB_CUR_MAX)
		{
			p->mb_cur = -1;
			return ;
		}
		size = size + ft_val_wchar(baba[j]);
	}
	j = -1;
	par->str = (char*)ft_memalloc(size + par->width + 100);
	if (par->flags[1] == 1)
		flag(par, j, baba);
	else
	{
		i = -1;
		while (++i < par->width - size)
			par->str[i] = ' ';
		while (baba[++j] != '\0')
			i = wstring_s(baba[j], par->str, i, 0);
	}
}
