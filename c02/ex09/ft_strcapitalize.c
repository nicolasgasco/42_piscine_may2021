/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:47:15 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/26 14:45:54 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char str)
{
	int		numeric;

	numeric = 1;
	if (str < 48 || str > 57)
	{
		numeric = 0;
	}
	return (numeric);
}

int	ft_str_is_alpha(char str)
{
	int		alpha;

	alpha = 1;
	if (str < 65 || str > 122 || (str >= 91 && str <= 96))
		alpha = 0;
	return (alpha);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		new_word;

	new_word = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (ft_str_is_alpha(*(str + i)))
		{
			if (*(str + i) >= 65 && *(str + i) <= 90)
				*(str + i) = *(str + i) + 32;
			if ((new_word == 1 || i == 0))
			{
				if (*(str + i) >= 97 && *(str + i) <= 122)
					*(str + i) = *(str + i) - 32;
				new_word = 0;
			}
		}
		else if (ft_str_is_numeric(*(str + i)))
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}
