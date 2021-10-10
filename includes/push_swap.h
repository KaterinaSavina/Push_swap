/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvargo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:21:49 by mvargo            #+#    #+#             */
/*   Updated: 2021/10/03 19:24:12 by mvargo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define A 1
# define B 2
# define ALL 3

typedef struct s_stack
{
	struct s_list	*first;
	int				i;
	struct s_list	*last;
}t_stack;

typedef struct s_list
{
	struct s_list	*pre;
	int				val;
	struct s_list	*next;
}t_list;

typedef struct s_value
{
	long	middle;
	long	min_middle;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}t_value;

void	all_free(t_stack *a, t_stack *b);
void	a_sorting_three_word(int r, t_stack *a);
void	b_sorting_three_word(int r, t_stack *a, t_stack *b);
void	duplicates(t_list *a);
void	five_word_stack(int i, t_stack *a, t_stack *b, int flag);
void	five_in_a(t_stack *a, t_stack *b);
int		ft_atoi(char *word);
char	**ft_split(char const *str, char c);
void	init_instruction(t_value *instruction);
t_list	*init_list(void);
t_stack	*init_stack(void);
void	init_min_max_mid(int r, t_stack *stack, t_value *instruction);
int		make_list(char *av, t_list **list, t_stack **stack);
t_list	*make_stack(int ac, char **av, t_stack **stack);
int		maximum(t_list *list, int i);
int		middle_five_massive(t_list *list);
int		minimum(t_list *list, int i);
void	move_to_a(int r, t_stack *a, t_stack *b, int *count);
void	move_to_b(int r, t_stack *a, t_stack *b, int *count);
void	push_stack1(t_stack *one, t_stack *two, int flag);
void	push_swap(t_stack *a, t_stack *b);
void	ra_rb(t_stack *stack, int flag);
void	rr_all_stacks(t_stack *a, t_stack *b, int flag);
void	rr_one_stack(t_stack *stack, int flag);
int		sorting_five_massive(int val[]);
void	sorting_two_word(t_stack *a, t_stack *b, int flag);
void	swap_stack(t_stack *stack, int flag);
void	three_word_stack(int r, t_stack *a, t_stack *b, int flag);
void	write_error(void);
int		word_is_int(char *word);

#endif
