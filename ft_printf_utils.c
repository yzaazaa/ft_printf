#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i++]);
	return (i - 1);
}

int	ft_putstr(char const *s)
{

	if(s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return(write(1, s, ft_strlen(s)));
}

int	ft_len(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	m;
	int		len;

	m = (long) n;
	len = ft_len(m);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (m < 0)
		m *= -1;
	s += len;
	*s = 0;
	if (m == 0)
		*--s = '0';
	while (m > 0)
	{
		*--s = m % 10 + '0';
		m /= 10;
	}
	if (n < 0)
		*--s = '-';
	return (s);
}

int	ft_putnbr(int n)
{
	char	*s;
	int	len;

	s = ft_itoa(n);
	len = ft_putstr(s);
	free(s);
	return (len);
}

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while(num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if(n <= 9)
			ft_putchar(n + '0');
		else
		{
			if(c == 'x')
				ft_putchar(n - 10 + 'a');
			else if(c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}	
}

int	ft_printhex(unsigned int num, char c)
{
	if(num == 0)
		return (ft_putchar('0'));
	else
		ft_puthex(num, c);
	return (hex_len(num));
}

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	long	m;
	int		len;

	m = (long) n;
	len = ft_len(m);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (m < 0)
		m *= -1;
	s += len;
	*s = 0;
	if (m == 0)
		*--s = '0';
	while (m > 0)
	{
		*--s = m % 10 + '0';
		m /= 10;
	}
	return (s);
}

int	ft_putuint(unsigned int n)
{
	int	len;
	char	*s;

	len = 0;
	if(n == 0)
		len += ft_putchar('0');
	else
	{
		s = ft_uitoa(n);
		len += ft_putstr(s);
		free(s);
	}
	return (len);
}

int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while(num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t num)
{
	if(num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if(num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;

	if(ptr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		ft_putptr(ptr);
		len += ptr_len(ptr);
	}
	return(len);
}
