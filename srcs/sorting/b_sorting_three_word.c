/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sorting_three_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:01:53 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:04:11 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_three_word_first(t_stack *b, int max)
{
	if (b->i == 3)
	{
		ra_rb(b, B);
		if (b->first->next->val == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		ra_rb(b, B);
		swap_stack(b, B);
		rr_one_stack(b, B);
		if (b->first->next->val == max)
			swap_stack(b, B);
	}
}

void	b_three_word_second(t_stack *b, int max)
{
	if (b->i == 3)
	{
		rr_one_stack(b, B);
		if (b->first->next->val == max)
			swap_stack(b, B);
	}
	else
	{
		ra_rb(b, B);
		swap_stack(b, B);
		rr_one_stack(b, B);
		if (b->first->next->val == max)
			swap_stack(b, B);
	}
}

void	b_three_word_last(t_stack *b, int max)
{
	if (b->first->next->val == max)
		swap_stack(b, B);
}

void	b_sorting_three_word(int r, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = minimum(b->first, r);
	max = maximum(b->first, r);
	if (b->first->val == min)
		b_three_word_first(b, max);
	else if (b->first->next->val == min)
		b_three_word_second(b, max);
	else if (b->first->next->next->val == min)
		b_three_word_last(b, max);
	push_stack1(b, a, A);
	push_stack1(b, a, A);
	push_stack1(b, a, A);
}
