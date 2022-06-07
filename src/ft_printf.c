/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:54:18 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/07 21:10:57 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	print_uint(unsigned int nbr)
{
	int	size;

	size = 0;
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', 1);
		size++;
	}
	else
	{
		size += print_uint(nbr / 10);
		ft_putchar_fd(nbr % 10 + '0', 1);
		size++;
	}
	return (size);
}

static int	print_hexa(unsigned int nbr, char spec)
{
	int	size;

	size = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
		{
			if (spec == 'x')
				ft_putchar_fd('a' + (nbr - 10), 1);
			else
				ft_putchar_fd('A' + (nbr - 10), 1);
		}
		size++;
	}
	else
	{
		size += print_hexa(nbr / 16, spec);
		if (nbr % 16 < 10)
			ft_putchar_fd(nbr % 16 + '0', 1);
		else
		{
			if (spec == 'x')
				ft_putchar_fd('a' + (nbr % 16 - 10), 1);
			else
				ft_putchar_fd('A' + (nbr % 16 - 10), 1);
		}
		size++;
	}
	return (size);
}

/*static int	print_pointer(void *ptr)
{
	(void)ptr;
	ft_putstr_fd("should be a pointer", 1);
	return (0);
}*/

static int	print_conversions(char spec, va_list ptr)
{
	int		ret_value;
	char	*str;

	ret_value = 1;
	if (spec == 'c')
		ft_putchar_fd(va_arg(ptr, int), 1);
	else if (spec == '%')
		ft_putchar_fd('%', 1);
	else if (spec == 's')
	{
		str = va_arg(ptr, char *);
		if (str == NULL)
		{
			ret_value = 6;
			ft_putstr_fd("(null)", 1);
		}
		else
		{
			ret_value += ft_strlen(str) - 1;
			ft_putstr_fd(str, 1);
		}
	}
	else if (spec == 'd' || spec == 'i')
	{
		str = ft_itoa(va_arg(ptr, int));
		if (str != NULL)
		{
			ret_value += ft_strlen(str) - 1;
			ft_putstr_fd(str, 1);
			free(str);
		}
		else
			ret_value = 0;
	}
	else if (spec == 'u')
		ret_value += print_uint(va_arg(ptr, unsigned int)) - 1;
	else if (spec == 'x' || spec == 'X')
		ret_value += print_hexa(va_arg(ptr, unsigned int), spec) - 1;
	else if (spec == 'p')
	{
		ret_value += print_hexa(va_arg(ptr, unsigned int), 'x') - 1;
	}
	return (ret_value);
}

static int	print_prev_str(const char *str, int i, int j)
{
	size_t	size;
	char	to_print;

	size = 0;
	while (j < i)
	{
		to_print = (char)str[j];
		ft_putchar_fd(to_print, 1);
		size++;
		j++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	size_t	size;
	size_t	i;
	size_t	j;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	j = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (i > j)
				size += print_prev_str(str, i, j);
			i++;
			size += print_conversions(str[i], ptr);
			j = i + 1;
		}
		i++;
	}
	if (i > j)
		size += print_prev_str(str, i, j);
	va_end(ptr);
	return (size);
}

/*int main(void)
{
	ft_printf("\n%d\n", ft_printf("aahsajk%-+8d\n", 5));
}*/
