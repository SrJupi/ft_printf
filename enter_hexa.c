/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:36:23 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/15 15:37:57 by lsulzbac         ###   ########.fr       */
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
		if (spec == 'X')
			temp = ft_putchar('A' + (nbr - 10));
		else
			temp = ft_putchar('a' + (nbr - 10));
	}
	return (temp);
}

static int	print_hexa(unsigned long nbr, char spec)
{
	int	size;
	int	temp;

	size = 0;
	if (nbr < 16)
	{
		if (hexa_helper(nbr, spec) == -1)
			return (-1);
		size++;
	}
	else
	{
		temp = print_hexa(nbr / 16, spec);
		if (temp == -1)
			return (-1);
		size += temp;
		if (hexa_helper(nbr % 16, spec) == -1)
			return (-1);
		size++;
	}
	return (size);
}

int	enter_hexa(unsigned long nbr, char spec)
{
	int	size;
	int	temp;

	size = 0;
	if (spec == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		spec = 'x';
		size += 2;
	}
	temp = print_hexa(nbr, spec);
	if (temp == -1)
		return (-1);
	size += temp;
	return (size);
}
