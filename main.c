/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:00:16 by abossard          #+#    #+#             */
/*   Updated: 2019/01/05 20:00:51 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#include <float.h>

int		main(int argc, const char *argv[])
{
	double	hey;

	hey = -1.42;
	ft_printf("ME:: [%F]\n", hey);
	printf("VR:: [%F]\n", hey);
	return (0);
}
