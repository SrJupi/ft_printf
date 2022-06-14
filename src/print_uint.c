/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:06:23 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/14 18:05:41 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_helper(long *nbr, int *size)
{
	int	temp;

	temp = ft_putchar('-');
	if (temp == -1)
		return (-1);
	*size += temp;
	if (*nbr == -2147483648)
	{
		temp = ft_putchar('2');
		if (temp == -1)
			return (-1);
		*size += temp;
		*nbr += 2000000000;
	}
	*nbr *= -1;
	return (temp);
}

int	print_uint(long nbr)
{
	int	size;
	int	temp;

	size = 0;
	if (nbr < 0)
	{
		if (uint_helper(&nbr, &size) == -1)
			return (-1);
		temp = print_uint(nbr);
		if (temp == -1)
			return (-1);
		size += temp;
	}
	else if (nbr < 10)
	{
		temp = ft_putchar(nbr + '0');
		if (temp == -1)
			return (-1);
		size += temp;
	}
	else
	{
		temp = print_uint(nbr / 10);
		if (temp == -1)
			return (-1);
		size += temp;
		temp = ft_putchar(nbr % 10 + '0');
		if (temp == -1)
			return (-1);
		size += temp;
	}
	return (size);
}
