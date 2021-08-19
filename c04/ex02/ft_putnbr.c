/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 08:43:02 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/30 08:52:43 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_lowest(void)
{
	write(1, "2", 1);
	write(1, "1", 1);
	write(1, "4", 1);
	write(1, "7", 1);
	write(1, "4", 1);
	write(1, "8", 1);
	write(1, "3", 1);
	write(1, "6", 1);
	write(1, "4", 1);
	write(1, "8", 1);
}

void	ft_recursive_write(int nb)
{
	char	result;

	if (nb == 0)
	{
		return ;
	}
	ft_recursive_write(nb / 10);
	result = nb % 10 + '0';
	write(1, &result, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
		ft_print_lowest();
	else
		ft_recursive_write(nb);
}
