/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 19:01:42 by abossard         ###   ########.fr       */
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
			while (format[p->i] != 'n' && format[p->i] != 's'
					&& format[p->i]!= 'S' && format[p->i] != 'p'
					&& format[p->i] != 'd' && format[p->i] != 'D'
					&& format[p->i] != 'i' && format[p->i] != 'o'
					&& format[p->i] != 'O' && format[p->i] != 'u'
					&& format[p->i] != 'U' && format[p->i] != 'x'
					&& format[p->i] != 'X' && format[p->i] != 'c'
					&& format[p->i] != 'C' && format[p->i] != 'f'
					&& format[p->i] != '%' && format[p->i] != '\0')
				p->i++;
			if (format[p->i] != '%' && format[p->i] != '\0')
				p->nbr++;
			p->tab[p->nbr][0] = format[p->i];
			if (p->tab[p->nbr][0] == 'f')
			{
				p->tab[p->nbr][1] = format[p->i - 1];
				p->tab[p->nbr][2] = format[p->i - 2];
			}
		}
		p->i++;
	}
//	printf("-----------------\n| nbr d'arg = %d |\n-----------------\n", NBR);
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
		if (p->tab[p->i + 1][0] == 'f')
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
//		printf("ptr->arg = %lld\n", (long long int)ptr->arg);
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
	p->i = 0;
	p->j = 0;
	while (format[p->i] != '\0')
	{
		if (format[p->i] == '%')
			boucle_ppale(format, p);
		p->i++;
	}
	p->par->str = ft_strsub(format, p->j, (p->i - p->j));
	p->size_buf = p->size_buf + ft_strlen(PAR->str);
	p->par = p->para_beg;
	/*	while (PAR != NULL)
		{
		printf("~~~~~~~~~~~~~~~~~\n| the line is: %s |\n", PAR->str);
		PAR = PAR->next;
		} */
	if (p->mb_cur == -1)
	{
		delete_infos(&p);
		return (-1);
	}
	display(p, p->para_beg);
	return (delete_infos(&p));
}

//#include <locale.h>

//int		main(int ac, char **av)
//{
//	int		s;
//	s = 0;
//	wchar_t		s[4];
//	s[0] = 0x53;
//	s[1] = 0x3abc;
//	s[2] = 0x81000;
//	s[3] = '\0';
//	char* l = setlocale(LC_ALL, ""); 
//	if (l == NULL) 
//		printf("Locale not set\n"); 
//	else
//		printf("Locale set to %s\n", l); 
//	ft_printf(av[1], '\0');
//	printf("\n\n%-10c\n\n", '\0');
//	ft_putnbr(s);
//	while(1);
//}
