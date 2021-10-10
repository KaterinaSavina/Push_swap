/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:40:43 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:42:05 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *stack, int flag)
{
	t_list	*tmp;
	t_list	*first_next;

	if (stack->i < 2)
		return ;
	tmp = stack->first;
	first_next = stack->first->next;
	stack->last->next = tmp;
	tmp->pre = stack->last;
	tmp->next = NULL;
	stack->last = tmp;
	stack->first = first_next;
	stack->first->pre = NULL;
	if (flag == A)
		write(1, "ra\n", 3);
	else if (flag == B)
		write(1, "rb\n", 3);
}
