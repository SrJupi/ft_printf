/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:54:18 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/15 16:42:24 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ret_value = enter_hexa(va_arg(ptr, unsigned int), spec);
	else if (spec == 'p')
		ret_value += enter_hexa(va_arg(ptr, unsigned long), 'p');
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
