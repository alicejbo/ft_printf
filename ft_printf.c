/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2018/07/19 23:47:45 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_args(const char *format, t_infos *p)
{
	I = 0;
	while (format[I] != '\0')
	{
		if (format[I] == '%')
		{
			I++;
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
	printf("nbr d'arg = %d\n", NBR);
	return (NBR);
}

void	fill_list(const char *format, t_infos *p, va_list ap)
{
	t_args	*ptr;

	NBR = count_args(format, p);
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

	p = ft_memalloc(sizeof(t_infos));
	PAR = init_params(&p->para_beg);
	va_start(ap, format);
	fill_list(format, p, ap);
	I = 0;
	J = 0;
	while (format[I] != '\0')
	{
		if (format[I] == '%')
			boucle_ppale(format, p);
		I++;
	}
	PAR->str = ft_strsub(format, J, (I - J));
	PAR = p->para_beg;
	while (PAR != NULL)
	{
		printf("the line is: %s\n", PAR->str);
		PAR = PAR->next;
	} 
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf(av[1], "bite", "de", "cheval", "feuille", "de", "bricks", "je", 
			"te", "kiffe", "mon", "coeur");
}
