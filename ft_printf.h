/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 03:58:12 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/14 22:39:48 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	check(int tmp, int len);
int	ft_putnbr(int nbr);
int	ft_putuint(unsigned int n);
int	ft_printptr(unsigned long long ptr);
int	ft_printhex(unsigned int num, int c);
int	ft_printf(const char *str, ...);

#endif
