/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:40:56 by abossard          #+#    #+#             */
/*   Updated: 2018/07/08 06:22:52 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args		*init_args(t_args **begin_list)
{
	t_args		*element;

	if (*begin_list == NULL)
	{
		*begin_list = malloc(sizeof(t_args));
		return(*begin_list);
	}
	else
	{
		element = *begin_list;
		while (element != NULL)
			element = element->next;
		element = NULL;
		element = ft_memalloc(sizeof(t_args));
	}
	return(element);
}

void		delete_args(t_args **begin_list)
{
	t_args		*element;
	t_args		*delete;

	element = *begin_list;
	while (element != NULL)
	{
		delete = element;
		element = element->next;
		free(delete);
	}
	*begin_list = NULL;
}
