/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:47:11 by abossard          #+#    #+#             */
/*   Updated: 2017/12/05 00:00:58 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	char	*res;

	if (!s || !f)
		return (NULL);
	if (!(tmp = ft_strdup(s)))
		return (NULL);
	res = tmp;
	while (*s != '\0')
	{
		*tmp = f(*s);
		s++;
		tmp++;
	}
	return (res);
}
