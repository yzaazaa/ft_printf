#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
void	ft_putnbr_base(int nbr, char *base);
int	ft_printf(const char *s, ...);
#endif