/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:20:30 by abossard          #+#    #+#             */
/*   Updated: 2017/12/04 23:36:27 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && s[i] != '\0')
		i++;
	while (j > 0 && ft_isspace(s[j]))
		j--;
	j++;
	if (i > j)
		return (ft_strdup(""));
	str = ft_strsub(s, i, (j - i));
	return (str);
}
