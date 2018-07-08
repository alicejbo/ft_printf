/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:54:09 by abossard          #+#    #+#             */
/*   Updated: 2017/11/22 15:27:19 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tempo;

	tempo = (unsigned char *)b;
	while (len > 0)
	{
		*tempo = (unsigned char)c;
		tempo++;
		len--;
	}
	return (b);
}
