/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2018/07/09 09:00:30 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_args(const char *format, t_infos *p)
{
	int		nbr;

	nbr = 0;
	while (format[I] != '\0')
	{
		if(format[I] == '%')
		{
			I++;
			while(format[I] != 'n' && format[I] != 'c' && format[I]
					!= 'd' && format[I] != 'i' && format[I] != 'x' &&
					format[I] != 'X' && format[I] != 'p' && 
					format[I] != 'e' && format[I] != 'E' &&
					format[I] != 'F' && format[I] != 'f' &&
					format[I] != 'g' && format[I] != 'G' &&
					format[I] != 'o' && format[I] != 's' &&
					format[I] != '%')
				I++;
			if (format[I] != '%' && format[I] != 'n')
				nbr++;
		}
		I++;
	}
	return (nbr);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_infos		*p;
	int			nbr;

	va_start(ap, format);
	p = ft_memalloc(sizeof(t_infos));
	nbr = count_args(format, p);
	printf("nbr d'arg = %d\n", nbr);
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf(av[1]);
}
