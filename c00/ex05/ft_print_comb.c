/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:35:46 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/23 09:53:18 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
char	g_int1;
char	g_int1 = '0';
char	g_int2;
char	g_int2 = '0';
char	g_int3;
char	g_int3 = '0';

void	ft_print_comb(void)
{
	while (g_int1 <= '9')
	{	
		while (g_int2 <= '9')
		{
			while (g_int3 <= '9')
			{
				if (g_int1 < g_int2 && g_int2 < g_int3)
				{
					ft_putchar(g_int1);
					ft_putchar(g_int2);
					ft_putchar(g_int3);
					if (g_int1 != '7' || g_int2 != '8' || g_int3 != '9')
					{
						ft_putchar(',');
						ft_putchar(' ');
					}
				}
				g_int3++;
			}
			g_int3 = '0';
			g_int2++;
		}
		g_int2 = '0';
		g_int1++;
	}
}

int main()
{
	ft_print_comb();
}
