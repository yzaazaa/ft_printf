/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 03:57:37 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/18 00:20:18 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		len += ft_putuint(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'x' || c == 'X')
		len += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else
		len += ft_putchar(c);
	return (len);
}

static void	init_arg(int *len, int *i)
{
	*len = 0;
	*i = 0;
}

static int	ft_print(int *len, char c, va_list args)
{
	int	tmp;

	tmp = *len;
	*len += ft_format(c, args);
	if (check(tmp, *len) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		tmp;

	init_arg(&len, &i);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '\0')
				return (va_end(args), len);
			if (ft_print(&len, str[i++], args) == -1)
				return (va_end(args), -1);
		}
		else
		{
			tmp = len;
			len += ft_putchar(str[i++]);
			if (check(tmp, len) == -1)
				return (va_end(args), -1);
		}
	}
	return (va_end(args), len);
}
