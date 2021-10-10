/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:37:34 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:40:24 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_one(t_stack *one, t_stack *two)
{
	if (two->i == 0)
	{
		two->first = one->first;
		two->last = two->first;
	}
	else
	{
		two->first->pre = one->first;
		one->first->next = two->first;
		two->first = two->first->pre;
	}
	one->first = NULL;
	one->last = NULL;
}

void	push_stack2(t_stack *one, t_stack *two)
{
	if (one->i == 1)
		only_one(one, two);
	else
	{
		if (two->i == 0)
		{
			two->first = one->first;
			two->last = two->first;
			one->first = one->first->next;
			one->first->pre = NULL;
			two->first->next = NULL;
		}
		else
		{
			two->first->pre = one->first;
			one->first = one->first->next;
			one->first->pre = NULL;
			two->first->pre->next = two->first;
			two->first = two->first->pre;
		}
	}
	two->i++;
	one->i--;
}

void	push_stack1(t_stack *one, t_stack *two, int flag)
{
	if (one->i == 0)
		return ;
	push_stack2(one, two);
	if (flag == A)
		write(1, "pa\n", 3);
	else if (flag == B)
		write(1, "pb\n", 3);
}
