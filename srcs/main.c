/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:28:05 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:30:48 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	av_is_sorted(t_stack *a)
{
	t_list	*list;

	list = a->first;
	while (list)
	{
		if (list->next)
		{
			if (list->val > list->next->val)
				return (0);
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
	if (list->val == a->last->val)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{	
	t_stack	*a;
	t_stack	*b;

	if (ac > 1)
	{		
		a = init_stack();
		a->first = make_stack(ac, av, &a);
		duplicates(a->first);
		b = init_stack();
		if (av_is_sorted(a))
		{
			all_free(a, b);
			return (0);
		}
		push_swap(a, b);
		all_free(a, b);
	}
	return (0);
}
