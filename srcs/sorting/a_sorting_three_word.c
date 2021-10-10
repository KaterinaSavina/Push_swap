/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sorting_three_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:58:30 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:01:35 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three_word_first(t_stack *a, int max)
{
	if (a->i == 3)
	{
		if (a->first->next->val == max)
		{
			rr_one_stack(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->first->next->val == max)
		{
			ra_rb(a, A);
			swap_stack(a, A);
			rr_one_stack(a, A);
		}
	}
}

void	a_three_word_second(t_stack *a, int max)
{
	if (a->i == 3)
	{
		if (a->last->val == max)
			swap_stack(a, A);
		else
			ra_rb(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->first->next->val == max)
		{
			ra_rb(a, A);
			swap_stack(a, A);
			rr_one_stack(a, A);
		}
	}
}

void	a_three_word_last(t_stack *a, int max)
{
	if (a->i == 3)
	{
		if (a->first->val == max)
			swap_stack(a, A);
		rr_one_stack(a, A);
	}
	else
	{
		if (a->first->val == max)
			swap_stack(a, A);
		ra_rb(a, A);
		swap_stack(a, A);
		rr_one_stack(a, A);
		swap_stack(a, A);
	}
}

void	a_sorting_three_word(int r, t_stack *a)
{
	int	min;
	int	max;

	min = minimum(a->first, r);
	max = maximum(a->first, r);
	if (a->first->val == min)
		a_three_word_first(a, max);
	else if (a->first->next->val == min)
		a_three_word_second(a, max);
	else if (a->first->next->next->val == min)
		a_three_word_last(a, max);
}
