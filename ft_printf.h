/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:51:18 by abossard          #+#    #+#             */
/*   Updated: 2018/07/04 08:02:57 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg>

struct		flags
{
	int		size_str;
	char	*str;
	int		flags[5];
	int		width;
	int		prec;
	int		length;
	char	c;
	char	i;
	char	d;
	char	x;
	char	X;
	char	p;
	char	e;
	char	E;
	char	f;
	char	F;
	char	g;
	char	G;
	char	o;
	char	u;
	char	s;
	char	%;
};

#endif
