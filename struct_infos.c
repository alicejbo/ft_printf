/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:01:13 by abossard          #+#    #+#             */
/*   Updated: 2018/07/10 05:24:44 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		delete_infos(t_infos **begin_list)
{
	t_infos		*p;

	p = *begin_list;
	ft_strdel(&p->buf);
	delete_args(&p->args_beg);
	delete_params(&p->para_beg);
	free(begin_list);
	*begin_list = NULL;
}
