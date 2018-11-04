/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:17 by abossard          #+#    #+#             */
/*   Updated: 2018/11/04 21:12:55 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char			*ft_itoa_base(long long int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = (value >= 10) ? 1 : 0;
	neg = 0;
	if (value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value = -value;
	}
	while (ft_pow(base, i) - 1 < value / base)
		i++;
	nbr = (char*)ft_memalloc(sizeof(nbr) * ++i);
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
