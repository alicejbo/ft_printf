/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:01:13 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 16:59:38 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		delete_infos(t_infos **begin_list)
{
	t_infos		*p;
	int			res;

	p = *begin_list;
	res = p->size_buf;
	ft_strdel(&p->buf);
	delete_args(&p->args_beg);
	delete_params(&p->para_beg);
	free(*begin_list);
	*begin_list = NULL;
	return (res);
}
