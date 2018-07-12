/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:51:18 by abossard          #+#    #+#             */
/*   Updated: 2018/07/12 05:13:28 by abossard         ###   ########.fr       */
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
#define NBR p->nbr
#define J p->j
#define PAR p->par

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
	t_params			*par;
	int					order;
	int					i;
	int					j;
	int					nbr;
}						t_infos;

/*
** ft_printf.c
*/

int			count_args(const char *format, t_infos *p);
void		fill_list(const char *format, t_infos *p, va_list ap);
int			ft_printf(const char *format, ...);

/*
** list_args.c
*/

t_args		*init_args(t_args **begin_list);
void		delete_args(t_args **begin_list);

/*
** list_params.c
*/

t_params	*init_params(t_params **begin_list);
void		delete_params(t_params **begin_list);

/*
** struct_infos.c
*/

void		delete_infos(t_infos **begin_list);

/*
** parse_args.c
*/

void		parse_args1(char *str, t_infos *p, t_params *par);

/*
** boucle_ppale.c
*/

void		boucle_ppale(const char *format, t_infos *p);



#endif
