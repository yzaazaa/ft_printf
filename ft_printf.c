#include "ft_printf.h"

static void	ft_format(char c, va_list args)
{
	if(c == 'c')
		ft_putchar(va_arg(args, int));
	else if(c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if(c == 's')
		ft_putstr(va_arg(args, char *));
	else if(c == 'u')
		ft_putnbr((int)va_arg(args, unsigned int));
	else if(c == '%')
		ft_putchar('%');
	else if(c == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if(c ==  'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else
		return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%')
		{
			i++;
			ft_format(s[i], args);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (i);
}