/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:01:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/21 11:40:47 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar2(char x)
{
	ft_putchar('0');
	ft_putchar(x);
}

void	ft_putchar_zero(int c)
{	
	char	b;
	char	d;
	char	e;

	d = c % 10 + '0';
	e = c / 10 + '0';
	if (c <= 9)
	{
		b = c + '0';
		ft_putchar2(b);
	}
	else
	{
		write(1, &e, 1);
		write(1, &d, 1);
	}
}

void	ft_print_comb2(void)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (i1 <= 98)
	{
		while (i2 <= 99)
		{
			if (i2 != i1 && i1 < i2)
			{
				ft_putchar_zero(i1);
				ft_putchar(' ');
				ft_putchar_zero(i2);
				if (i1 != 98 || i2 != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			i2++;
		}
		i2 = 0;
		i1++;
	}
}
