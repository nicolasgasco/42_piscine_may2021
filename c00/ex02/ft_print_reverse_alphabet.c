/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:45:09 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/20 10:48:50 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{	
	char	currentChar;

	currentChar = 'z';
	while (currentChar >= 'a')
	{
		ft_putchar(currentChar);
		currentChar--;
	}
}	
