/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:09:59 by abossard          #+#    #+#             */
/*   Updated: 2018/12/09 23:25:10 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_args7(t_infos *p, t_params *par)
{
	p->pos_arg = p->pos_arg + 1;
	if (par->type == 'a')
		p->pos_arg = p->pos_arg - 1;
	which_arg(p, par);
//	printf("@@@@@@@@@@@@@@@@@\n| which arg %lld   |\n", (long long int)par->w_arg);
//	printf("| pos arg %d     |\n@@@@@@@@@@@@@@@@@\n", p->pos_arg);
	ft_strdel(&par->str);
	direction1(p, par);
}

void	parse_args6(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	 if (str[K] == 'p')
		 par->type = 'p';
	 if (str[K] == 'n')
		 par->type = 'n';
	 if (str[K] == 'D')
		 par->type = 'i';
	 if (str[K] == 'O')
		 par->type = 'o';
	 if (str[K] == 'U')
		 par->type = 'u';
	 if (str[K] >= 68 && str[K] <= 87)
		 par->length = 3;
	 if (str[K] == '%')
		 par->type = 'a';
	priorities(par);
	parse_args7(p, par);
}

void	parse_args5(char *str, t_infos *p, t_params *par)
{
	par->str = str;

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
	 if (str[K] == 'C')
		 par->type = 'C';
	 if (str[K] == 'S')
		 par->type = 'S';
	 if (str[K] == 'f')
		 par->type = 'f';
	parse_args6(str, p, par);
}
