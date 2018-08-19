/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 00:02:44 by abossard          #+#    #+#             */
/*   Updated: 2018/08/20 00:40:05 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display(t_infos *p, t_params *par)
{
	p->buf = ft_memalloc(sizeof(char) * p->size_buf + 1);
	while (par)
	{
		ft_strcat(p->buf, par->str);
		par = par->next;
	}
	write(1, "\n", 1);
	write(1, p->buf, p->size_buf);
	write(1, "\n", 1);
}
