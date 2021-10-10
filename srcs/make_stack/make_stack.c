/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:46:03 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:49:09 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->i = 0;
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->val = 0;
	list->next = NULL;
	list->pre = NULL;
	return (list);
}

void	connect_list(t_list **tmp, t_list **list, t_stack **stack)
{
	if (!*list)
	{
		*list = *tmp;
		(*stack)->first = *list;
	}
	else
	{
		(*list)->next = *tmp;
		(*tmp)->pre = *list;
		*list = (*list)->next;
	}
}

int	make_list(char *av, t_list **list, t_stack **stack)
{
	int		i;
	char	**word;
	t_list	*tmp;

	word = ft_split(av, ' ');
	if (!word || !*word)
		return (0);
	i = -1;
	while (word[++i])
	{
		tmp = init_list();
		if (!tmp)
			write_error();
		tmp->val = ft_atoi(word[i]);
		connect_list(&tmp, list, stack);
		(*stack)->i++;
		free(word[i]);
	}
	free(word);
	return (1);
}

t_list	*make_stack(int ac, char **av, t_stack **stack)
{
	int		x;
	int		ret;
	t_list	*list;

	x = 0;
	list = NULL;
	while (++x < ac)
	{
		ret = make_list(av[x], &list, stack);
		if (!ret)
			write_error();
	}
	if (!list->next)
		(*stack)->last = list;
	while (list->pre)
		list = list->pre;
	return (list);
}
