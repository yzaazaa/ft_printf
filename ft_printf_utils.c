#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i++]);
	return (i - 1);
}

void	ft_putstr(char const *s)
{
	if(s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if(n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if(n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if(n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void    ft_putnbr_base(int nbr, char *base)
{
    int     i;
    int     j;
    int     len_base;

    i = 0;
    len_base = ft_strlen(base);
    if(len_base < 2)
        return ;
    while(i < len_base - 1)
    {   
        j = i + 1;
        while(j < len_base)
        {
            if(base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
                return ;
            j++;
        }
        i++;
    }
    if(nbr == 0)
    {
        ft_putchar(base[0]);
        return ;
    }

    if(nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr != 0)
	{
		if ((nbr / len_base) != 0)
			ft_putnbr_base(nbr / len_base, base);
        nbr = nbr % len_base;
}

void	ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	
	unsigned char *t = (unsigned char *)addr;
	size_t		i = 0;
	int			col;
	size_t		tmp = 0;

	while (i < size)
	{
		col = -1;
		tmp = i;
		while (++col < 16)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_putnbr_base(t[i], "0123456789ABCDEF");
			}
			else
				ft_putstr("  ");
			ft_putchar((i & 1) << 6);
			i++;
		}
		col = -1;
		i = tmp;
		while (++col < 16 && i < size)
			ft_printchars(t[i++]);
		ft_putchar('\n');
	}
}
