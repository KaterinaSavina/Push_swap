/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:43:40 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:45:01 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, int flag)
{
	t_list	*tmp;
	t_list	*first_next;

	if (stack->i < 2)
		return ;
	first_next = stack->first->next;
	tmp = stack->first;
	if (stack->i > 2)
		first_next->next->pre = stack->first;
	tmp->next = first_next->next;
	stack->first = first_next;
	stack->first->pre = NULL;
	stack->first->next = tmp;
	tmp->pre = stack->first;
	if (stack->i == 2)
		stack->last = stack->first->next;
	if (flag == A)
		write(1, "sa\n", 3);
	else if (flag == B)
		write(1, "sb\n", 3);
}
