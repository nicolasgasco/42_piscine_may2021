/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:36:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/26 09:11:10 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{	
	int	i;
	int	printable;

	i = 0;
	printable = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 127)
		{
			printable = 0;
			break ;
		}
		i++;
	}
	return (printable);
}
