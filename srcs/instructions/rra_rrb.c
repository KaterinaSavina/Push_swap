/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:42:19 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:43:24 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_one_stack(t_stack *stack, int flag)
{
	t_list	*tmp;
	t_list	*last_pre;

	if (stack->i < 2)
		return ;
	tmp = stack->last;
	last_pre = stack->last->pre;
	stack->first->pre = tmp;
	tmp->next = stack->first;
	tmp->pre = NULL;
	stack->first = tmp;
	stack->last = last_pre;
	stack->last->next = NULL;
	if (flag == A)
		write(1, "rra\n", 4);
	else if (flag == B)
		write(1, "rrb\n", 4);
}

void	rr_all_stacks(t_stack *a, t_stack *b, int flag)
{
	rr_one_stack(a, flag);
	rr_one_stack(b, flag);
	if (flag == ALL)
		write(1, "rrr\n", 4);
}
