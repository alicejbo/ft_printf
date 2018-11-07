/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:19:30 by abossard          #+#    #+#             */
/*   Updated: 2018/11/07 03:57:36 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_val_wchar(wchar_t letter)
{
	int size;

	size = 0;
	if (letter <= 0x7F)
		size = 1;
	else if (letter <= 0x7FF)
		size = 2;
	else if (letter <= 0xFFFF)
		size = 3;
	else if (letter <= 0x10FFFF)
		size = 4;
	return (size);
}
