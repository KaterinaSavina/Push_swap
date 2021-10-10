/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:49:40 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:54:00 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_of_word(char const *str, char c)
{
	size_t		count;
	bool		is_word;

	count = 0;
	is_word = false;
	while (*str)
	{
		if (is_word == false && *str != c)
		{
			count++;
			is_word = true;
		}
		else if (is_word == true && *str == c)
			is_word = false;
		str++;
	}
	return (count);
}

static size_t	number_of_word(char *str, char c, size_t order)
{
	bool		is_word;
	size_t		count;
	size_t		position;

	is_word = false;
	count = 0;
	position = 0;
	while (*(str + position))
	{
		if (is_word == false && *(str + position) != c)
		{
			count++;
			if (count == order + 1)
				break ;
			is_word = true;
		}
		else if (is_word == true && *(str + position) == c)
			is_word = false;
		position++;
	}
	return (position);
}

static char	*create_word(char *str, char c)
{
	size_t		x;
	size_t		lenght;
	char		*result;

	lenght = 0;
	while (*(str + lenght) && *(str + lenght) != c)
		lenght++;
	result = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!result)
		return (0);
	x = 0;
	while (x < lenght)
		*(result + (x++)) = *str++;
	*(result + x) = '\0';
	return (result);
}

char	**ft_split(char const *str, char c)
{
	size_t		w_count;
	size_t		x;
	char		**result;
	char		*tmp;

	if (!str)
		return (NULL);
	tmp = (char *)str;
	w_count = count_of_word(tmp, c);
	result = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!result)
		return (0);
	x = 0;
	while (x < w_count)
	{
		*(result + x) = create_word(tmp + number_of_word(tmp, c, x), c);
		x++;
	}
	*(result + x) = 0;
	return (result);
}

int	ft_atoi(char *word)
{
	int			x;
	int			minus;
	long long	val;

	if (!word_is_int(word))
		write_error();
	x = 0;
	minus = 1;
	val = 0;
	if (word[x] == '+' || word[x] == '-')
	{
		if (word[x++] == '-')
			minus = -1;
	}
	while (word[x])
		val = val * 10 + (word[x++] - '0');
	val = val * minus;
	if (val > INT_MAX || val < INT_MIN)
		write_error();
	return (val);
}
