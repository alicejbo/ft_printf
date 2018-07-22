/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:09:59 by abossard          #+#    #+#             */
/*   Updated: 2018/07/20 16:52:12 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_args5(char *str, t_infos *p, t_params *par);

void	parse_args4(char *str, t_infos *p, t_params *par)
{
	par->str = str;

	 if (str[K] == 'c')
		 par->type = 'c';
	 if(str[K] == 'd' || str[K] == 'i'
	parse_args5(str, p, par);
}
