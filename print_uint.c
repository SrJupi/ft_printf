/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:06:23 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/14 18:48:32 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_negatives(long nbr, int *size)
{
	int	temp;

	temp = ft_putchar('-');
	if (temp == -1)
		return (-1);
	*size += temp;
	if (nbr == -2147483648)
	{
		temp = ft_putchar('2');
		if (temp == -1)
			return (-1);
		*size += temp;
		nbr += 2000000000;
	}
	nbr *= -1;
	temp = print_uint(nbr);
	if (temp == -1)
		return (-1);
	*size += temp;
	return (temp);
}

static int	uint_big(long nbr, int *size)
{
	int	temp;

	temp = print_uint(nbr / 10);
	if (temp == -1)
		return (-1);
	*size += temp;
	if (ft_putchar(nbr % 10 + '0') == -1)
		return (-1);
	*size += 1;
	return (1);
}

int	print_uint(long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		if (uint_negatives(nbr, &size) == -1)
			return (-1);
	}
	else if (nbr < 10)
	{
		if (ft_putchar(nbr + '0') == -1)
			return (-1);
		size++;
	}
	else
	{
		if (uint_big(nbr, &size) == -1)
			return (-1);
	}
	return (size);
}
