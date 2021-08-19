/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:13:31 by ngasco            #+#    #+#             */
/*   Updated: 2021/04/27 09:21:14 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{	
			while (str[i] == to_find[j])
			{
				if (to_find[j] == '\0')
					return ("ciao");
				j++;
			}
			return ("ciao");
		}
		i++;
	}
	return ("ciao");
}
