/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_cargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:54:19 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 19:59:24 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	boucle_cargs(const char *format, t_infos *p)
{
	while (format[p->i] != 'n' && format[p->i] != 's'
			&& format[p->i] != 'S' && format[p->i] != 'p'
			&& format[p->i] != 'd' && format[p->i] != 'D'
			&& format[p->i] != 'i' && format[p->i] != 'o'
			&& format[p->i] != 'O' && format[p->i] != 'u'
			&& format[p->i] != 'U' && format[p->i] != 'x'
			&& format[p->i] != 'X' && format[p->i] != 'c'
			&& format[p->i] != 'C' && format[p->i] != 'f'
			&& format[p->i] != 'F' && format[p->i] != '%'
			&& format[p->i] != '\0')
		p->i++;
}
