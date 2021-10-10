/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:08:13 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 20:12:45 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	five_or_three_word(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		three_word_stack(r, a, b, A);
		return (0);
	}
	else if (r == 5)
	{
		five_word_stack(5, a, b, A);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_a(t_stack *a, t_stack *b, t_value *instruction)
{
	if (a->first->val > instruction->middle)
	{
		ra_rb(a, A);
		instruction->ra++;
	}
	else
	{
		push_stack1(a, b, B);
		instruction->pb++;
		if (b->first->val > instruction->min_middle)
		{
			ra_rb(b, B);
			instruction->rb++;
		}
	}
}

static void	rotate_stack_ra(t_stack *a, t_stack *b, int *count, t_value *ins)
{
	int	rb;
	int	r;

	rb = ins->rb;
	r = ins->ra - rb;
	if ((*count) > 0)
	{
		while (rb--)
			rr_all_stacks(a, b, ALL);
		while (r--)
			rr_one_stack(a, A);
	}
	else
	{
		while (rb--)
			rr_one_stack(b, B);
	}
}

static void	rotate_stack_rb(t_stack *a, t_stack *b, int *count, t_value *ins)
{
	int	ra;
	int	r;

	ra = ins->ra;
	r = ins->rb - ra;
	if ((*count) > 0)
	{
		while (ra--)
			rr_all_stacks(a, b, ALL);
		while (r--)
			rr_one_stack(b, B);
	}
	else
	{
		ra = ins->rb;
		while (ra--)
			rr_one_stack(b, B);
	}
}

void	move_to_b(int r, t_stack *a, t_stack *b, int *count)
{
	int		r_temp;
	t_value	instruction;

	if (!five_or_three_word(r, a, b))
		return ;
	init_instruction(&instruction);
	init_min_max_mid(r, a, &instruction);
	r_temp = r;
	while (r_temp--)
		push_rotate_a(a, b, &instruction);
	if (instruction.ra > instruction.rb)
		rotate_stack_ra(a, b, count, &instruction);
	else
		rotate_stack_rb(a, b, count, &instruction);
	move_to_b(instruction.ra, a, b, count);
	move_to_a(instruction.rb, a, b, count);
	move_to_a(instruction.pb - instruction.rb, a, b, count);
}
