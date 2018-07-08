/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:53:11 by abossard          #+#    #+#             */
/*   Updated: 2017/12/05 00:09:01 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		n;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	i += ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		res[n] = s1[i];
		n++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		res[n] = s2[i];
		n++;
	}
	res[n] = '\0';
	return (res);
}
