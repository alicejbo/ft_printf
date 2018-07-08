/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:10:14 by abossard          #+#    #+#             */
/*   Updated: 2017/11/30 22:45:06 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	ret;

	i = 0;
	j = 0;
	ret = ft_strlen(dst);
	len = size - 1;
	if (size > ret)
	{
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && i + j < len)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (ret + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
