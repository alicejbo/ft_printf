/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:55:41 by abossard          #+#    #+#             */
/*   Updated: 2018/11/03 19:23:21 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_u(t_params *par, char *baba)
{
	int diff;
	int i;
	char *baba2;

	diff = (par->prec - ft_strlen(baba));
	baba2 = ft_memalloc(par->size_str);
	i = 0;
	while (i < diff)
	{
		baba2[i] = '0';
		i++;
	}
	ft_strcpy(baba2 + i, baba);
	return (baba2);
}

char	*rempli_u(t_params *par, char *baba, int size_nb)
{
	int		i;
	char	*nb_preci;

	i = 0;
	if ((size_t)par->prec > ft_strlen(baba))
	{
		nb_preci = ft_strdup(baba);
		ft_strdel(&baba);
		baba = prec_u(par, nb_preci);
		ft_strdel(&nb_preci);
	}
	if (par->size_str > size_nb)
		flag_u2(par, baba, size_nb);
	else
		ft_strcat(par->str, baba);
	return (baba);
}

char	*length_u(t_params *par)
{
	char	*baba;

	if (par->length == 0)
		baba = ft_itoa_base_ll((unsigned int)par->w_arg, 10);
	if (par->length == 1)
		baba = ft_itoa_base_ll((unsigned short int)par->w_arg, 10);
	if (par->length == 2)
		baba = ft_itoa_base_ll((unsigned char)par->w_arg, 10);
	if (par->length == 3)
		baba = ft_itoa_base_ll((unsigned long int)par->w_arg, 10);
	if (par->length == 4)
		baba = ft_itoa_base_ll((unsigned long long int)par->w_arg, 10);
	if (par->length == 5)
		baba = ft_itoa_base_ll((uintmax_t)par->w_arg, 10);
	if (par->length == 6)
		baba = ft_itoa_base_ll((ssize_t)par->w_arg, 10);
	return(baba);
}

void	flag_u(t_params *par)
{
	char	*baba;
	int		size_nb;

	baba = length_u(par);
	par->size_str = ft_strlen(baba);
	size_nb = ft_strlen(baba);
//	printf("^^^^^^^^^^^^^^^^^\n| taille baba = %d|\n^^^^^^^^^^^^^^^^^\n\nchar aba = %s\n", 
//			par->size_str, baba);
//	printf("argggg =   %d\n", (long long int)p->args_beg->arg);
	if (par->size_str < par->width)
		par->size_str = par->width;
	if (size_nb < par->prec)
		size_nb = par->prec;
	if (size_nb > par->size_str)
		par->size_str = size_nb;
//	printf("size 2 = %d\n\n", par->size_str);
	par->str = ft_memalloc(par->size_str);
	baba = rempli_u(par, baba, size_nb);
	ft_strdel(&baba);
}
