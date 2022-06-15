/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:55:24 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/08 18:01:55 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_helper(unsigned long nbr, char spec)
{
	int	temp;

	if (nbr < 10)
		temp = ft_putchar(nbr + '0');
	else
	{
		if (spec == 'x')
			temp = ft_putchar('a' + (nbr - 10));
		else
			temp = ft_putchar('A' + (nbr - 10));
	}
	return (temp);
}

int	print_hexa(unsigned long nbr, char spec)
{
	int	size;
	int	temp;

	size = 0;
	if (nbr < 16)
	{
		temp = hexa_helper(nbr, spec);
		if (temp == -1)
			return (-1);
		size += temp;
	}
	else
	{
		temp = print_hexa(nbr / 16, spec);
		if (temp == -1)
			return (-1);
		size += temp;
		temp = hexa_helper(nbr % 16, spec);
		if (temp == -1)
			return (-1);
		size += temp;
	}
	return (size);
}
