/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:48:10 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/15 22:21:41 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_helper_ptr(int *len, int *tmp, unsigned long long num, int c)
{
	if (num <= 9)
	{
		*tmp = *len;
		*len += ft_putchar(num + '0');
		if (*tmp == *len + 1)
			return (-1);
	}
	else
	{
		*tmp = *len;
		if (c == 'x')
			*len += ft_putchar(num - 10 + 'a');
		else if (c == 'X')
			*len += ft_putchar(num - 10 + 'A');
		if (*tmp == *len + 1)
			return (-1);
	}
	return (1);
}

static int	ft_putptr(unsigned long long num, int *len, int c)
{
	int	tmp;

	tmp = 0;
	if (num >= 16)
	{
		if (ft_putptr(num / 16, len, c) == -1)
			return (-1);
		if (ft_putptr(num % 16, len, c) == -1)
			return (-1);
	}
	else if (ft_helper_ptr(len, &tmp, num, c) == -1)
		return (-1);
	return (*len);
}

int	ft_printhex(unsigned int num, int c)
{
	int					len;
	int					tmp;
	unsigned long long	n;

	len = 0;
	tmp = 0;
	n = (unsigned long long)num;
	ft_putptr(n, &len, c);
	if (tmp == len + 1)
		return (-1);
	return (len);
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = 0;
	len += write(1, "0x", 2);
	if (len == -1)
		return (-1);
	tmp = len;
	ft_putptr(ptr, &len, 'x');
	if (tmp == len + 1)
		return (-1);
	return (len);
}
