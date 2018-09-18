/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:26:58 by abossard          #+#    #+#             */
/*   Updated: 2018/09/18 19:34:45 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_nbr(long long int nb)
{
	long long int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char					*ft_itoa_ll(long long int n)
{
	long long int	i;
	char			*str;

	i = 0;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = (n < 0) ? i + 1 : i;
	i = i + ft_nbr(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n >= 10)
	{
		i--;
		str[i] = n % 10 + 48;
		n = n / 10;
	}
	i--;
	str[i] = n + 48;
	return (str);
}
