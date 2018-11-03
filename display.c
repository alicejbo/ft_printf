/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 00:02:44 by abossard          #+#    #+#             */
/*   Updated: 2018/11/03 19:02:46 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strnncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (n--)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

void	display(t_infos *p, t_params *par)
{
	p->buf = ft_memalloc(sizeof(char) * p->size_buf + 1);
	while (par)
	{
		if ((par->type == 'c' || par->type == 'C') 
				&& (unsigned char)par->w_arg == '\0')
			ft_strnncat(p->buf, par->str, par->size_str);
		else
			ft_strcat(p->buf, par->str);
		par = par->next;
	}
	//ft_putnbr(p->size_buf);
//	write(1, "\n", 1);
	write(1, p->buf, p->size_buf);
//	write(1, "\n", 1);
}
