/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2018/07/10 06:56:41 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_args(const char *format, t_infos *p)
{
	I = 0;
	while (format[I] != '\0')
	{
		if (format[I++] == '%')
		{
			while (format[I] != 'n' && format[I] != 'c' && format[I]
					!= 'd' && format[I] != 'i' && format[I] != 'x' &&
					format[I] != 'X' && format[I] != 'p' && 
					format[I] != 'e' && format[I] != 'E' &&
					format[I] != 'F' && format[I] != 'f' &&
					format[I] != 'g' && format[I] != 'G' &&
					format[I] != 'o' && format[I] != 's' &&
					format[I] != '%' && format[I] != '\0')
				I++;
			if (format[I] != '%' && format[I] != 'n' && format[I] != '\0')
				NBR++;
		}
		I++;
	}
	return (NBR);
}

void	fill_list(const char *format, t_infos *p, va_list ap)
{
	t_args	*ptr;

	I = 0;

	while (I < NBR)
	{
		ptr = init_args(&p->args_beg);
		ptr->arg = va_arg(ap, void*);
		I++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_infos		*p;
	t_args		*q;

	va_start(ap, format);
	p = ft_memalloc(sizeof(t_infos));
	NBR = count_args(format, p);
	fill_list(format, p, ap);
	q = p->args_beg;
	while (q != NULL)
	{
		printf("fill list = %s\n", q->arg);
		q = q->next;
	}
	printf("nbr d'arg = %d\n", NBR);
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf(av[1], "bite", "de", "cheval", "feuille", "de", "bricks", "je", 
			"te", "kiffe", "mon", "coeur");
}
