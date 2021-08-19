/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:02:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/29 10:04:32 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int		result;

	result = 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (nb != 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
