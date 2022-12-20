#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
int	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int	ft_putstr(const char *s);
int	ft_len(long n);
char	*ft_itoa(int n);
int	ft_putnbr(int n);
int	hex_len(unsigned int num);
int	octal_len(unsigned int num);
void	ft_puthex(unsigned int n, char c);
void	ft_putoctal(unsigned int n);
int	ft_printhex(unsigned int num, char c);
int	ft_printoctal(unsigned int num);
char	*ft_uitoa(unsigned int n);
int	ft_putuint(unsigned int n);
int	ptr_len(uintptr_t num);
void	ft_putptr(uintptr_t num);
int	ft_printptr(unsigned long long ptr);
int	ft_printf(const char *s, ...);
#endif
