/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:40 by abossard          #+#    #+#             */
/*   Updated: 2018/09/30 22:42:39 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_neg(t_infos *p, t_params *par, char *baba, int size_nb);

void	ft_pos(t_infos *p, t_params *par, char *baba, int size_nb)
{
	if (par->flags[1] == 1)
	{
	}

}

	if (baba[0] >= '0' && baba[0] <= '9')
		ft_pos(p, par, baba, size_nb);
	else if (baba[0] == '-')
		ft_neg(p, par, baba, size_nb);

void	flag_i2(t_infos *p, t_params *par, char *baba, int size_nb)
{
	if (par->flags[1] == 1)
		xxxx;
	else if (par->flags[3] == 1)
		xxxx;
	else if (par->flags[0] == 1)
		xxxx;
	else if (par->flags[4] == 1)
		xxxx;
	else
		xxxx;
}
