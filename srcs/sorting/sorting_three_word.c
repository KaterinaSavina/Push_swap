/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:21:16 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:22:56 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two_word(t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
	{
		if (a->first->val > a->first->next->val)
			swap_stack(a, A);
	}
	else
	{
		if (b->first->val < b->first->next->val)
			swap_stack(b, B);
		push_stack1(b, a, A);
		push_stack1(b, a, A);
	}
}

void	three_word_stack(int r, t_stack *a, t_stack *b, int flag)
{
	if (r == 3)
	{
		if (flag == A)
			a_sorting_three_word(r, a);
		else
			b_sorting_three_word(r, a, b);
	}
	else if (r == 2)
		sorting_two_word(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			push_stack1(b, a, A);
	}
}
