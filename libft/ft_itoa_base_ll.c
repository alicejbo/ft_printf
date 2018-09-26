/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:39:05 by abossard          #+#    #+#             */
/*   Updated: 2018/09/25 17:42:36 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_ll(unsigned long long int value, int base)
{
	int						i;
	char					*nbr;
	unsigned long long int	tmp;

	tmp = value;
	i = (value == 0) ? 1 : 0;
	while		(tmp)
	{
		tmp = tmp / base;
		i++;
	}
	nbr = (char*)ft_memalloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
