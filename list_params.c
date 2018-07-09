/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 08:25:59 by abossard          #+#    #+#             */
/*   Updated: 2018/07/09 07:27:27 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*init_params(t_params **begin_list)
{
	t_params	*element;

	if (*begin_list == NULL)
	{
		printf("e\n");
		*begin_list = ft_memalloc(sizeof(t_params));
		return(*begin_list);
	}
	else
	{
		printf("f\n");
		element = *begin_list;
		while (element != NULL)
			element = element->next;
		element = NULL;
		element = ft_memalloc(sizeof(t_params));
	}
	return(element);
}

void		delete_params(t_params **begin_list)
{
	t_params	*element;
	t_params	*delete;

	element = *begin_list;
	while (element != NULL)
		{
			printf("g\n");
			delete = element;
			element = element->next;
			free(delete);
			printf("h\n");
		}
	*begin_list = NULL;
}
