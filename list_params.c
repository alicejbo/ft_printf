/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 08:25:59 by abossard          #+#    #+#             */
/*   Updated: 2018/07/12 03:50:57 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*init_params(t_params **begin_list)
{
	t_params	*element;

	if (*begin_list == NULL)
	{
		*begin_list = ft_memalloc(sizeof(t_params));
		return(*begin_list);
	}
	else
	{
		element = *begin_list;
		while (element->next != NULL)
			element = element->next;
		element->next = ft_memalloc(sizeof(t_params));
	}
	return(element->next);
}

void		delete_params(t_params **begin_list)
{
	t_params	*element;
	t_params	*delete;

	element = *begin_list;
	while (element != NULL)
		{
			delete = element;
			element = element->next;
			free(delete);
		}
	*begin_list = NULL;
}
