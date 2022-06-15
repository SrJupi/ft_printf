/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:01:15 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/06/08 18:03:18 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
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
}
