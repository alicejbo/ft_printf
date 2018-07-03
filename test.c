/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 02:57:40 by abossard          #+#    #+#             */
/*   Updated: 2018/07/03 06:00:04 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ma_printf(char *str, ...)
{
	va_list ap;
	int i;
	int d;
	char c;
	char *s;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				s = va_arg(ap, void*);
				write(1, s, ft_strlen(s));
			}
			if (str[i + 1] == 'd')
			{
				d = (int)va_arg(ap, void*);
				write(1, ft_itoa(d), ft_strlen(ft_itoa(d)));
			}
			if (str[i + 1] == 'c')
			{
				c = (char)va_arg(ap, void*);
				ft_itoa(c);
			}
			i++;
		}
		else
			write(1, str + i, 1);
			i++;
	}
	va_end(ap);
}

int		main()
{
	char *nom;
	int age;

	age = 19;
	nom = "Alice";
	ma_printf("Je m'appelle %s, j'ai %d ans\n", nom, age);
	return (0);
}
