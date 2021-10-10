/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:25:36 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:27:50 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*list;
	t_list	*tmp;

	list = stack->first;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		if (tmp)
			list = tmp;
		else
			break ;
	}
	free(stack);
}

void	all_free(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
