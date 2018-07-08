/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:01:41 by abossard          #+#    #+#             */
/*   Updated: 2017/12/04 23:57:03 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tmp = ft_strdup(s)))
		return (NULL);
	res = tmp;
	while (*s != '\0')
	{
		*tmp = f(i, *s);
		s++;
		tmp++;
		i++;
	}
	return (res);
}
