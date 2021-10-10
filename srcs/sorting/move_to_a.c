/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:04:36 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:07:51 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	five_or_three_word(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		three_word_stack(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		five_word_stack(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_b(t_stack *a, t_stack *b, t_value *instruction)
{
	if (b->first->val <= instruction->min_middle)
	{
		ra_rb(b, B);
		instruction->rb++;
	}	
	else
	{
		push_stack1(b, a, A);
		instruction->pa++;
		if (a->first->val <= instruction->middle)
		{
			ra_rb(a, A);
			instruction->ra++;
		}
	}
}

static void	rotate_stack_ra(t_stack *a, t_stack *b, t_value *instruction)
{
	int	rb;
	int	r;

	rb = instruction->rb;
	r = instruction->ra - rb;
	while (rb--)
		rr_all_stacks(a, b, ALL);
	while (r--)
		rr_one_stack(a, A);
}

static void	rotate_stack_rb(t_stack *a, t_stack *b, t_value *instruction)
{
	int	ra;
	int	r;

	ra = instruction->ra;
	r = instruction->rb - ra;
	while (ra--)
		rr_all_stacks(a, b, ALL);
	while (r--)
		rr_one_stack(b, B);
}

void	move_to_a(int r, t_stack *a, t_stack *b, int *count)
{
	int		r_temp;
	t_value	var;

	(*count)++;
	if (!five_or_three_word(r, a, b))
		return ;
	init_instruction(&var);
	init_min_max_mid(r, b, &var);
	r_temp = r;
	while (r_temp--)
		push_rotate_b(a, b, &var);
	move_to_b(var.pa - var.ra, a, b, count);
	if (var.ra > var.rb)
		rotate_stack_ra(a, b, &var);
	else
		rotate_stack_rb(a, b, &var);
	move_to_b(var.ra, a, b, count);
	move_to_a(var.rb, a, b, count);
}
