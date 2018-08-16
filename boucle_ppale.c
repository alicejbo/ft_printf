/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_ppale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:53:33 by abossard          #+#    #+#             */
/*   Updated: 2018/08/16 03:38:28 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	boucle_ppale(const char *format, t_infos *p)
{
	PAR->str = ft_strsub(format, J, (I - J));
	J = I;
	I++;
	PAR->size_str = ft_strlen(PAR->str);
	PAR = init_params(&p->para_beg);
	while(format[I] != 'n' && format[I] != 's' && format[I]
			!= 'S' && format[I] != 'p' && format[I] != 'd' &&
			format[I] != 'D' && format[I] != 'i' && 
			format[I] != 'o' && format[I] != 'O' &&
			format[I] != 'u' && format[I] != 'U' &&
			format[I] != 'x' && format[I] != 'X' &&
			format[I] != 'c' && format[I] != 'C' &&
			format[I] != '%' && format[I + 1] != '\0')
		I++;
	parse_args1(ft_strsub(format, J, ((I - J) + 1)), p, PAR);
	J = I + 1;
	printf("flags 0 = %d\n", PAR->flags[0]);
	printf("flags 1 = %d\n", PAR->flags[1]);
	printf("flags 2 = %d\n", PAR->flags[2]);
	printf("flags 3 = %d\n", PAR->flags[3]);
	printf("flags 4 = %d\n", PAR->flags[4]);
	printf("width = %d\n", PAR->width);
	printf("precision = %d\n", PAR->prec);
	printf("length = %d\n", PAR->length);
	printf("type = %c\n", PAR->type);
	PAR = init_params(&p->para_beg);
}
