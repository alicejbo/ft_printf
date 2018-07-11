/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:14:05 by abossard          #+#    #+#             */
/*   Updated: 2018/07/11 07:28:28 by abossard         ###   ########.fr       */
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
	printf("nbr d'arg = %d\n", NBR);
	return (NBR);
}

void	fill_list(const char *format, t_infos *p, va_list ap)
{
	t_args	*ptr;

	I = 0;
	NBR = count_args(format, p);
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
	t_params	*par;

	p = ft_memalloc(sizeof(t_infos));
	I = 0;
	J = 0;
	par = init_params(&p->para_beg);
	va_start(ap, format);
	fill_list(format, p, ap);
	while (format[I] != '\0')
	{
		if (format[I] == '%')
		{
			par->str = ft_strsub(format, J, (I - J));
			J = I;
			par->size_str = ft_strlen(par->str);
			par = init_params(&p->para_beg);
			while(format[I] != 'n' && format[I] != 'c' && format[I]
					!= 'd' && format[I] != 'i' && format[I] != 'x' &&
					format[I] != 'X' && format[I] != 'p' && 
					format[I] != 'e' && format[I] != 'E' &&
					format[I] != 'F' && format[I] != 'f' &&
					format[I] != 'g' && format[I] != 'G' &&
					format[I] != 'o' && format[I] != 's' &&
					format[I] != '%' && format[I] != '\0')
				I++;
			parse_args(ft_strsub(format, J, ((I - J) + 1)), p, par);
			J = I;
			par = init_params(&p->para_beg);
		}
		I++;
	}
	par->str = ft_strsub(format, J, (I - J));
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf(av[1], "bite", "de", "cheval", "feuille", "de", "bricks", "je", 
			"te", "kiffe", "mon", "coeur");
}
