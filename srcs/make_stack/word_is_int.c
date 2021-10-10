/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_is_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:54:30 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:57:49 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	lengt_of_word(char *word)
{
	int	x;
	int	lenght;

	x = 0;
	lenght = 0;
	if (word[0] == '+' || word[0] == '-')
	{
		x++;
		lenght--;
	}
	while (word[x] == '0')
		x++;
	while (word[x++])
		lenght++;
	return (lenght);
}

int	is_numeric(char *word)
{
	int	i;

	if (!word)
		return (0);
	i = -1;
	if (word[0] == '+' || word[0] == '-')
		i++;
	while (word[++i])
	{
		if (!ft_isdigit(word[i]))
			return (0);
	}
	return (1);
}

int	word_is_int(char *word)
{
	int	lenght;

	lenght = lengt_of_word(word);
	if (!is_numeric(word) || lenght > 11 || lenght < 0)
		return (0);
	else
		return (1);
}

void	duplicates(t_list *a)
{
	int		cur_value;
	t_list	*tmp;

	while (a->next)
	{
		tmp = a->next;
		cur_value = a->val;
		while (tmp)
		{
			if (tmp->val == cur_value)
				write_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->pre)
		a = a->pre;
}
