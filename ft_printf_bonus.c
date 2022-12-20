#include "ft_printf_bonus.h"

static int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if(c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if(c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if(c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if(c == 'u')
		len += ft_putuint(va_arg(args, unsigned int));
	else if(c == '%')
		len += ft_putchar('%');
	else if(c == 'x' || c == 'X')
		len += ft_printhex(va_arg(args, unsigned int), c);
	else if(c == 'p')
		len += ft_printptr(va_arg(args,unsigned long long));
	return (len);
}

static int	ft_bonus(char c, char c1, va_list args)
{
	int	len;
	int	x;

	len = 0;
	if(c == ' ' && (c1 == 'd' || c1 == 'i'))
	{
		x = va_arg(args, int);
		if(x >= 0)
			len += write(1, " ", 1);
		len += ft_putnbr(x);
	}
	else if(c == '#')
	{
		if(c1 == 'x' || c1 == 'X')
		{
			x = va_arg(args, int);
			if(x != 0)
			{
				if(c1 == 'x')
					len += write(1, "0x", 2);
				else if(c1 == 'X')
					len += write(1, "0X", 2);
			}
			len += ft_printhex(x, c1);
		}
		else if(c1 == 'o')
		{
			len += write(1, "0", 1);
			len += ft_printoctal(va_arg(args, int));
		}
	}
	else if(c == '+' && (c1 == 'd' || c1 == 'i'))
	{
		x = va_arg(args, int);
		if(x >= 0)
			len += write(1, "+", 1);
		len += ft_putnbr(x);
	}
	return (len);	
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%')
		{
			i++;
			if(s[i] == '#' || s[i] == ' ' || s[i] == '+')
			{
				len += ft_bonus(s[i], s[i + 1], args);
				i++;
			}
			else
				len += ft_format(s[i], args);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
