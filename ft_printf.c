/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 20:00:55 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_args(const char *format, t_infos *p)
{
	p->i = 0;
	while (format[p->i] != '\0')
	{
		if (format[p->i] == '%')
		{
			p->i++;
			boucle_cargs(format, p);
			if (format[p->i] != '%' && format[p->i] != '\0')
				p->nbr++;
			p->tab[p->nbr][0] = format[p->i];
			if (p->tab[p->nbr][0] == 'f' || p->tab[p->nbr][0] == 'F')
			{
				p->tab[p->nbr][1] = format[p->i - 1];
				p->tab[p->nbr][2] = format[p->i - 2];
			}
		}
		p->i++;
	}
	return (p->nbr);
}

void	fill_list(const char *format, t_infos *p, va_list ap)
{
	t_args	*ptr;

	p->nbr = count_args(format, p);
	p->i = 0;
	while (p->i < p->nbr)
	{
		ptr = init_args(&p->args_beg);
		if (p->tab[p->i + 1][0] == 'f' || p->tab[p->i + 1][0] == 'F')
		{
			if ((p->tab[p->i + 1][1] == 'Q' && p->tab[p->i + 1][2] == 'Q')
					|| p->tab[p->i + 1][1] == 'L')
				ptr->ld1 = va_arg(ap, long double);
			else if (p->tab[p->i + 1][1] == 'H')
				ptr->f1 = va_arg(ap, double);
			else if ((p->tab[p->i + 1][1] != 'Q' && p->tab[p->i + 1][2] != 'Q')
					&& p->tab[p->i + 1][1] != 'H' && p->tab[p->i + 1][1] != 'L')
				ptr->d1 = va_arg(ap, double);
		}
		ptr->arg = va_arg(ap, void*);
		p->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_infos		*p;

	p = ft_memalloc(sizeof(t_infos));
	p->pos_arg = -1;
	p->par = init_params(&p->para_beg);
	va_start(ap, format);
	fill_list(format, p, ap);
	p->i = -1;
	p->j = 0;
	while (format[++p->i] != '\0')
	{
		if (format[p->i] == '%')
			boucle_ppale(format, p);
	}
	p->par->str = ft_strsub(format, p->j, (p->i - p->j));
	p->size_buf = p->size_buf + ft_strlen(PAR->str);
	p->par = p->para_beg;
	if (p->mb_cur == -1)
	{
		delete_infos(&p);
		return (-1);
	}
	display(p, p->para_beg);
	return (delete_infos(&p));
}
