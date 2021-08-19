/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:53:50 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/02 16:05:03 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int		i;
	int		a;
	int		mult;
	int		result;

	a = 0;
	i = 0;
	mult = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = a * 10 + (str[i] - '0');
		a = result;
		i++;
	}
	return (result * mult);
}
