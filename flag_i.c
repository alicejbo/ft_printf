/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/09/26 19:58:04 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*length_i(t_infos *p, t_params *par, char *baba)
{
	if (par->length == 0)
		baba = ft_itoa_base((int)par->w_arg, 10);
	if (par->length == 4)
		baba = ft_itoa_base((long long int)par->w_arg, 10);
	if (par->length == 1)
		baba = ft_itoa_base_ll((short int)par->w_arg, 10);
	if (par->length == 2)
		baba = ft_itoa_base_ll((signed char)par->w_arg, 10);
	if (par->length == 3)
		baba = ft_itoa_base_ll((long int)par->w_arg, 10);
	if (par->length == 5)
		baba = ft_itoa_base_ll((uintmax_t)par->w_arg, 10);
	if (par->length == 6)
		baba = ft_itoa_base_ll((size_t)par->w_arg, 10);
	return(baba);
}

void	flag_i(t_infos *p, t_params *par)
{
	int		size;
	int		i;
	char	*baba;

	baba = length_i(p, par, baba);
	size = ft_strlen(baba);
	printf("^^^^^^^^^^^^^^^^^\n| taille baba = %d|\n^^^^^^^^^^^^^^^^^\n\nchar aba = %s\n", size, baba);
	printf("argggg =   %jd\n", (long long int)p->args_beg->arg);
	printf("length 2 = %i\n", par->length);
	printf("test = %s\n", ft_itoa_base(-1, 10));
	if (par->flags[0] == 1 || par->flags[4] == 1)
		if (baba[0] != '-')
			size++;
	if (size < par->width)
		size = par->width;
	
	printf("size 2 = %d\n\n", size);
	par->str = ft_memalloc(size);
}
