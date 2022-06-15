/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:54:18 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/14 18:25:36 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

/*static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *str)
{
	int	i;
	int	temp;

	i = 0;
	if (str == NULL)
	{
		temp = ft_putstr("(null)");
		if (temp == -1)
			return (temp);
		i = temp;
	}
	else
	{
		while (str[i])
		{
			temp = ft_putchar(str[i]);
			if (temp == -1)
				return (temp);
			i += temp;
		}
	}
	return (i);
}*/

/*static int	print_uint(long nbr)
{
	int	size;
	int	temp;

	size = 0;
	if (nbr < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		size += temp;
		if (nbr == -2147483648)
		{
			temp = ft_putchar('2');
			if (temp == -1)
				return (-1);
			size += temp;
			nbr += 2000000000;
		}
		nbr *= -1;
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
}*/

/*static int	hexa_helper(unsigned long nbr, char spec)
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

static int	print_hexa(unsigned long nbr, char spec)
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
}*/

static int	print_conversions(char spec, va_list ptr)
{
	int		ret_value;

	ret_value = 0;
	if (spec == 'c')
		ret_value = ft_putchar(va_arg(ptr, int));
	else if (spec == '%')
		ret_value = ft_putchar('%');
	else if (spec == 's')
		ret_value = ft_putstr(va_arg(ptr, char *));
	else if (spec == 'd' || spec == 'i')
		ret_value = print_uint(va_arg(ptr, int));
	else if (spec == 'u')
		ret_value = print_uint(va_arg(ptr, unsigned int));
	else if (spec == 'x' || spec == 'X')
		ret_value = print_hexa(va_arg(ptr, unsigned int), spec);
	else if (spec == 'p')
	{
		ret_value = ft_putstr("0x");
		if (ret_value == -1)
			return (-1);
		ret_value += print_hexa(va_arg(ptr, unsigned long), 'x');
		if (ret_value == 1)
			return (-1);
	}
	return (ret_value);
}

static int	ft_helper(const char *str, int *i, int *size, va_list ptr)
{
	int	temp;

	if (str[*i] == '%')
	{
		*i += 1;
		temp = print_conversions(str[*i], ptr);
		if (temp == -1)
			return (-1);
		*size += temp;
	}
	else
	{
		if (ft_putchar(str[*i]) == -1)
			return (-1);
		*size += 1;
	}
	*i += 1;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		size;
	int		i;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (ft_helper(str, &i, &size, ptr) == -1)
			return (-1);
	}
	va_end(ptr);
	return (size);
}
