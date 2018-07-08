/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:42:16 by abossard          #+#    #+#             */
/*   Updated: 2017/12/02 16:25:48 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*esp;
	size_t	i;

	i = 0;
	if (!(esp = malloc(size * sizeof(void))))
		return (0x0);
	while (i < size)
	{
		((unsigned char *)esp)[i] = 0;
		i++;
	}
	return (esp);
}
