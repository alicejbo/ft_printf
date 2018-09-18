/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/09/18 19:36:27 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_i(t_infos *p, t_params *par)
{
	int		size;
	int		i;
	char	*baba;

	baba = ft_itoa_ll((long long int)par->w_arg);
	size = ft_strlen(baba);
	printf("^^^^^^^^^^^^^^^^^\n| taille baba = %d|\n^^^^^^^^^^^^^^^^^\n\nchar baba =%s\n", size, baba);
	if (par->flags[0] == 1 || par->flags[4] == 1)
		if (baba[0] <= '0' && baba[0] != '-')
			size++;
	i = size;
	if (size < par->width)
		size = par->width;
	printf("size 2 = %d\n", size);
	par->str = ft_memalloc(size);
}
