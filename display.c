/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 00:02:44 by abossard          #+#    #+#             */
/*   Updated: 2018/11/04 18:33:17 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strnncat(char *s1, const char *s2, size_t n, int i)
{
	size_t	j;

	j = 0;
	while (n--)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return ((int)i);
}

static int		ft_strcatbis(char *s1, const char *s2, int i)
{
	int j;

	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return ((int)i);
}


void	display(t_infos *p, t_params *par)
{
	int		i;

	i = 0;
	p->buf = ft_memalloc(sizeof(char) * p->size_buf + 1);
	while (par)
	{
		if ((par->type == 'c' || par->type == 'C') 
				&& (unsigned char)par->w_arg == '\0')
			i = ft_strnncat(p->buf, par->str, par->size_str, i);
		else
			i = ft_strcatbis(p->buf, par->str, i);
		par = par->next;
	}
	//ft_putnbr(p->size_buf);
	write(1, p->buf, p->size_buf);
	//	write(1, "\n", 1);
}
