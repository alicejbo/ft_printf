/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:40:56 by abossard          #+#    #+#             */
/*   Updated: 2018/07/09 07:22:38 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args		*init_args(t_args **begin_list)
{
	t_args		*element;

	if (*begin_list == NULL)
	{
		printf("a\n");
		*begin_list = ft_memalloc(sizeof(t_args));
		return(*begin_list);
	}
	else
	{
		printf("b\n");
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
		printf("c\n");
		delete = element;
		element = element->next;
		free(delete);
		printf("d\n");
	}
	*begin_list = NULL;
}
