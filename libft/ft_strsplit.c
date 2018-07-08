/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:38:19 by abossard          #+#    #+#             */
/*   Updated: 2017/12/05 00:04:39 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compteur(const char *str, char c)
{
	int mot;
	int i;

	mot = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			mot++;
		i++;
	}
	if (str[0] != '\0')
		mot++;
	return (mot);
}

static char		*ft_mot(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		mot;
	char	**str;

	i = 0;
	j = 0;
	mot = ft_compteur(s, c);
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(str) * (mot + 2))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < mot && s[i])
	{
		str[j] = ft_mot(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
