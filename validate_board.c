#include <stdbool.h>
#include <stdio.h>
int	ft_parse_n_lines(char *str)
{
	int		i;
	int		a;
	int		mult;
	int		result;

	a = 0;
	i = 0;
	mult = 1;
	result = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		result = a * 10 + (str[i] - '0');
		a = result;
		i++;
	}
	return (result * mult);
}

void	ft_parse_chars(char *str, char *chars)
{
	int		i;
	int		n_char;

	i = 0;
	n_char = 0;
	while ((str[i] >= 20 && str[i] <= 127) && (str[i] != '\0' && str[i] != '\n'))
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			if (n_char == 0)
			{
				*(chars) = str[i];
				n_char++;
			}
			else if (n_char == 1)
			{
				*(chars + 1) = str[i];
				n_char++;
			}
			else
			{
				*(chars + 2) = str[i];
				break;
			}
		}
		i++;
	}
	*(chars + i) = '\0';
}

int	ft_check_if_printable(char **str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{	
			if (str[i][j] <= 20 || str[i][j] >= 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_line_lenght(char **str)
{
	int	line_len;
	int	line_len_comp;
	int	i;
	int j;

	line_len = 0;
	line_len_comp = 0;
	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (i == 0)
				line_len++;
			j++;
		}
		if (i != 0 && j != line_len)
			return (0);
		i++;
	}
	return (1);	
}

int	ft_check_if_obstacles(char **str, char obstacle)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == obstacle)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_check_newlines(char *str, int n_lines)
{
	int	i;
	int	newline_count;

	i = 0;
	newline_count = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	i++;
	while (str[i] != '\0')
	{	
		if (str[i] == '\n')
			newline_count++;
		i++;
	}
	if (newline_count == n_lines)
		return (1);
	return (0);
}

int	ft_validate_board(char **tab)
{
	int	i;
	int j;
	int n_lines;
	char chars[4];
	
	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s MAIN\n", tab[i]);
		i++;
	}
	printf("\nThe result of the line length check is %d \n", ft_check_line_lenght(tab));
	printf("The result of the obstacle check is %d \n", ft_check_if_obstacles(tab, 'o'));
	printf("The result of the is_printable check is %d \n", ft_check_if_printable(tab));
	/*
	n_lines = ft_parse_n_lines(tab);
	printf("Number of lines is %d\n", n_lines);
	ft_parse_chars(tab, chars);
	printf("Special characters are %s \n", chars);
	printf("The result of the newline check is %d \n". ft_check_newlines(tab, n_lines);
	*/
	return (1);
}
