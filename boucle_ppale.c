/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_ppale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:53:33 by abossard          #+#    #+#             */
/*   Updated: 2018/11/03 17:48:27 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	boucle_ppale(const char *format, t_infos *p)
{
	PAR->str = ft_strsub(format, J, (I - J));
	p->size_buf = p->size_buf + ft_strlen(PAR->str);
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
/*	printf("_________________\n| flags 0 = %d   |\n", PAR->flags[0]);
	printf("| flags 1 = %d   |\n", PAR->flags[1]);
	printf("| flags 2 = %d   |\n", PAR->flags[2]);
	printf("| flags 3 = %d   |\n", PAR->flags[3]);
	printf("| flags 4 = %d   |\n_________________\n", PAR->flags[4]);
	printf("+++++++++++++++++\n| width = %d    |\n+++++++++++++++++\n", PAR->width);
	printf("#################\n| precision = %d|\n#################\n", PAR->prec);
	printf("*****************\n| length = %d    |\n*****************\n", PAR->length);*/
//	printf("xxxxxxxxxxxxxxxxx\n| type = %c      |\nxxxxxxxxxxxxxxxxx\n", PAR->type);
	PAR = init_params(&p->para_beg);
}
