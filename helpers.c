/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:07:06 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/14 22:46:51 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i++], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	check(int tmp, int len)
{
	if (tmp == len + 1)
		return (-1);
	return (1);
}
