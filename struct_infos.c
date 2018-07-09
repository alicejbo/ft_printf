/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 05:01:13 by abossard          #+#    #+#             */
/*   Updated: 2018/07/09 06:51:43 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_infos		*init_infos(t_infos **begin_list)
{
	t_infos		*element;

	if (*begin_list == NULL)
	{
		*begin_list = malloc(sizeof(t_infos));
		return(*begin_list);
	}
	else
	{
		element = *begin_list;
		element = NULL;
		element = ft_memalloc(sizeof(t_infos));
	}
	return(element);
}

void		delete_infos(t_infos **begin_list)
{
	t_infos		*element;
	t_infos		*delete;

	element = *begin_list;
	while (element != NULL)
	{
		delete = element;
		free(delete);
	}
	*begin_list = NULL;
}
