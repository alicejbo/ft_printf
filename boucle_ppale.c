/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_ppale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:53:33 by abossard          #+#    #+#             */
/*   Updated: 2018/07/19 23:10:02 by abossard         ###   ########.fr       */
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
	while(format[I] != 'n' && format[I] != 'c' && format[I]
			!= 'd' && format[I] != 'i' && format[I] != 'x' &&
			format[I] != 'X' && format[I] != 'p' && 
			format[I] != 'e' && format[I] != 'E' &&
			format[I] != 'F' && format[I] != 'f' &&
			format[I] != 'g' && format[I] != 'G' &&
			format[I] != 'o' && format[I] != 's' &&
			format[I] != '%' && format[I] != '\0')
		I++;
	parse_args1(ft_strsub(format, J, ((I - J) + 1)), p, PAR);
	J = I + 1;
	PAR = init_params(&p->para_beg);
}
