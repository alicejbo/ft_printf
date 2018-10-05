/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <abossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 05:51:18 by abossard          #+#    #+#             */
/*   Updated: 2018/10/05 12:23:12 by abossard         ###   ########.fr       */
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
#define PAR p->par
#define J p->j
#define K p->k
#define L p->l

typedef struct			s_params
{
	int					size_str;
	char				*str;
	int					flags[5];
	int					width;
	int					prec;
	int					length;
	char				type;
	void				*w_arg;
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
	t_args				*arg_info;
	int					order;
	int					i;
	int					j;
	int					k;
	int					l;
	int					nbr;
	int					pos_arg;
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
void		priorities(t_params *par);
/*
** parse_args_2.c
*/

void		parse_args5(char *str, t_infos *p, t_params *par);

/*
** boucle_ppale.c
*/

void		boucle_ppale(const char *format, t_infos *p);

/*
** direction.c
*/

void		direction1(t_infos *p, t_params *par);

/*
** display.c
*/

void	display(t_infos *p, t_params *par);

/*
** which_arg.c
*/

void	which_arg(t_infos *p, t_params *par);

/*
** flag_i.c
*/

void	flag_i(t_infos *p, t_params *par);

/*
** flag_i2.c
*/

void	flag_i2(t_infos *p, t_params *par, char *baba, int size_nb);

/*
** flag_o.c
*/

void	flag_o(t_infos *p, t_params *par);

/*
** flag_o2.c
*/

void	flag_o2(t_infos *p, t_params *par, char *baba, int size_nb);

/*
** flag_u.c
*/

void	flag_u(t_infos *p, t_params *par);

/*
** flag_u2.c
*/

void	flag_u2(t_infos *p, t_params *par, char *baba, int size_nb);


#endif
