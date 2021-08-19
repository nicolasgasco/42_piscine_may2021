/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:07:59 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/01 08:21:59 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_rec_fibonacci(int a, int b, int index)
{
	int		temp;

	temp = 0;
	if (index == 0)
		return (b);
	else
	{
		temp = b;
		b = a + b;
		a = temp;
		index--;
		return (ft_rec_fibonacci(a, b, index));
	}
}

int	ft_fibonacci(int index)
{
	int		a;
	int		b;

	a = 0;
	b = 1;
	if (index == 0)
		return (0);
	else if (index < 0)
		return (-1);
	else
		return (ft_rec_fibonacci(a, b, index - 1));
}
