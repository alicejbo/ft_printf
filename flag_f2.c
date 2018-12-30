/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:29:48 by abossard          #+#    #+#             */
/*   Updated: 2018/12/30 20:30:41 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_arrondi(t_params *par, char *baba, int j)
{
	char	c;

	c = baba[j];
	baba[j] = '\0';
	if (c >= '5')
	{
		while (baba[--j] == '9')
			baba[j] = '0';
		if (baba[j] != '.')
			baba[j] = baba[j] + 1;
		else
		{
			--j;
			baba[j] = baba[j] +1;
		}
	}
	return (baba);
}

char	*rempli_f(t_params *par, char *baba, int size_nb)
{
	//	if ((int)ft_strlen(baba) > size_nb)
//	printf("%s => %d\n", baba, size_nb);
	baba = ft_arrondi(par, baba, size_nb);
//	printf("=>%s\n", baba);
	return (baba);
}
