/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:39:42 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/15 22:22:16 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_digits(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int nbr)
{
	int		len;
	long	n;

	n = (long)nbr;
	len = nb_digits(n);
	if (n < 0)
	{
		n = -n;
		if (ft_putchar('-') == -1)
			return (-1);
	}
	if (n > 9)
	{
		if (ft_putuint(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len);
}

int	ft_putuint(unsigned int n)
{
	int	len;

	len = nb_digits((long)n);
	if (n > 9)
	{
		if (ft_putuint(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len);
}
