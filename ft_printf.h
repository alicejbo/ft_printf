/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:51:18 by abossard          #+#    #+#             */
/*   Updated: 2018/07/09 07:14:06 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#define I p->i

typedef struct			s_params
{
	int					size_str;
	char				*str;
	int					flags[5];
	int					width;
	int					prec;
	int					length;
	char				type;
	struct s_params		*next;
}						t_params;

typedef struct			s_args
{
	void				*arg;
	struct s_args		*next;
}						t_args;

typedef struct			s_infos
{
	char				*buf;
	int					size_buf;
	t_params			*para_beg;
	t_args				*args_beg;
	int					order;
	int					i;
	int					j;
}						t_infos;

#endif
