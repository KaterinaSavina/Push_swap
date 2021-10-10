/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:35:54 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:36:51 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	init_instruction(t_value *instruction)
{
	instruction->ra = 0;
	instruction->rb = 0;
	instruction->pa = 0;
	instruction->pb = 0;
}

void	init_min_max_mid(int r, t_stack *stack, t_value *instruction)
{
	long	min;
	long	max;

	min = minimum(stack->first, r);
	max = maximum(stack->first, r);
	instruction->middle = (min + max) / 2;
	instruction->min_middle = (min + instruction->middle) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->i == 5)
		five_in_a(a, b);
	else
		move_to_b(a->i, a, b, &count);
}
