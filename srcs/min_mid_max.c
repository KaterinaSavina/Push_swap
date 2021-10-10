/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_mid_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:31:13 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:35:37 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_five_massive(int val[])
{
	int	x;
	int	y;
	int	tmp;

	x = 5;
	while (--x > 0)
	{
		y = -1;
		while (++y < x)
		{
			if (val[y] > val[y + 1])
			{
				tmp = val[y + 1];
				val[y + 1] = val[y];
				val[y] = tmp;
			}
		}
	}
	return (val[2]);
}

int	middle_five_massive(t_list *list)
{
	int	x;
	int	val[5];

	x = -1;
	while (++x < 5)
	{
		val[x] = list->val;
		if (list->next)
			list = list->next;
		else
			break ;
	}
	while (list->pre)
		list = list->pre;
	return (sorting_five_massive(val));
}

int	minimum(t_list *list, int i)
{
	int	min;

	min = list->val;
	while (i--)
	{
		if (min > list->val)
			min = list->val;
		if (list->next)
			list = list->next;
		else
			break ;
	}
	while (list->pre)
		list = list->pre;
	return (min);
}

int	maximum(t_list *list, int i)
{
	int	max;

	max = list->val;
	while (i--)
	{
		if (max < list->val)
			max = list->val;
		if (list->next)
			list = list->next;
		else
			break ;
	}
	while (list->pre)
		list = list->pre;
	return (max);
}
