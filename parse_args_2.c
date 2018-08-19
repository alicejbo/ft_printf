/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:09:59 by abossard          #+#    #+#             */
/*   Updated: 2018/08/20 00:50:35 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_args6(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	 if (str[K] == 'S')
		 par->type = 's';
	 if (str[K] == 'D')
		 par->type = 'd';
	 if (str[K] == 'O')
		 par->type = 'o';
	 if (str[K] == 'U')
		 par->type = 'u';
	 if (str[K] >= 68 && str[K] <= 87)
		 par->length = 3;
	priorities(par);
	ft_strdel(&par->str);
	direction1(p, par);
}

void	parse_args5(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	printf("\nferme la : %s\n", str + K);
	 if (str[K] == 'c')
		 par->type = 'c';
	 if (str[K] == 'd' || str[K] == 'i')
		 par->type = 'i';
	 if (str[K] == 'u')
		 par->type = 'u';
	 if (str[K] == 'o')
		 par->type = 'o';
	 if (str[K] == 'x')
		 par->type = 'x';
	 if (str[K] == 'X')
		 par->type = 'X';
	 if (str[K] == 's')
		 par->type = 's';
	 if (str[K] == 'p')
		 par->type = 'p';
	 if (str[K] == 'C')
		 par->type = 'C';
	parse_args6(str, p, par);
}
