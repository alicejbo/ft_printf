/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:16:11 by abossard          #+#    #+#             */
/*   Updated: 2018/12/21 17:02:31 by abossard         ###   ########.fr       */
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
		{
//			if (par->type != 'f')
				par->w_arg = p->arg_info->arg;
//			else
//			{
//				if (par->length == 10 || par->length == 7)
//					par->ld = p->arg_info->arg;
//				else if (par->length == 8)
//					par->f = p->arg_info->arg;
//				else if (par->length == 9 || par->length == 0)
//					par->d = p->arg_info->arg;
//			}
		}
		p->arg_info = p->arg_info->next;
	}
}
