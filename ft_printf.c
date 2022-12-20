#include "ft_printf.h"

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
