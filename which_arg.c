/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:16:11 by abossard          #+#    #+#             */
/*   Updated: 2018/09/12 21:00:06 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	which_arg(t_infos *p, t_params *par)
{
	int		count;

	count = -1;
	p->arg_info = p->args_beg;
	while (p->arg_info != NULL)
	{
		count++;
		if (count == p->pos_arg)
			par->w_arg = p->arg_info->arg;
		p->arg_info = p->arg_info->next;
	}
}
