/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:19:08 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:20:20 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sorting_five_word(int i, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = middle_five_massive(a->first);
	while (i--)
	{
		if (a->first->val < mid)
		{
			push_stack1(a, b, B);
			push++;
		}
		else
		{
			ra_rb(a, A);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		rr_one_stack(a, A);
}

void	b_sorting_five_word(int i, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = middle_five_massive(b->first);
	while (i--)
	{
		if (b->first->val >= mid)
		{
			push_stack1(b, a, A);
			push++;
		}
		else
		{
			ra_rb(b, B);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		rr_one_stack(b, B);
}

void	five_word_stack(int i, t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
		a_sorting_five_word(i, a, b);
	else
		b_sorting_five_word(i, a, b);
	a_sorting_three_word(3, a);
	sorting_two_word(a, b, B);
}

void	five_in_a(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = middle_five_massive(a->first);
	while (1)
	{
		if (a->first->val < mid)
		{
			push_stack1(a, b, B);
			pb++;
		}
		else
			ra_rb(a, A);
		if (pb == 2)
			break ;
	}
	a_sorting_three_word(3, a);
	sorting_two_word(a, b, B);
}
