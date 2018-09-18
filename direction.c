/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 23:41:40 by abossard          #+#    #+#             */
/*   Updated: 2018/09/12 23:10:34 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	direction1(t_infos *p, t_params *par)
{
	par->str = "\0";
	flag_i(p, par);
	//functions process
	//     |
	//     |
	//    \ /
	//     .

	p->size_buf = p->size_buf + ft_strlen(par->str);
}
