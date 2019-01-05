/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:16:11 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 19:39:07 by abossard         ###   ########.fr       */
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
			if (par->type != 'f' && par->type != 'F')
				par->w_arg = p->arg_info->arg;
			else
			{
				if (par->length == 10 || par->length == 7)
					par->ld = p->arg_info->ld1;
				else if (par->length == 8)
					par->f = p->arg_info->f1;
				else if (par->length == 0)
					par->d = p->arg_info->d1;
			}
		}
		p->arg_info = p->arg_info->next;
	}
}
