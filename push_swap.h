/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:55 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 17:18:58 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			a_size;
	int			b_size;
	int			count;
}	t_data;

double		calc_disorder(t_stack *stack);
t_data		*ft_datanew(t_stack *a, t_stack *b);
t_stack		*ft_lstnew(int content);
void		ft_lstdelone(t_stack *stack);
int			ft_lstsize(t_stack *stack);
t_stack		*ft_lstlast(t_stack *stack);
t_stack		*ft_lstpenultimate(t_stack *stack);
void		init_rank(t_stack *stack);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
int			ft_square(double value);
int			ft_max(t_stack *stack);
int			ft_min(t_stack *stack);
void		push_all_ab_let_one(t_data *data);
void		if_upper_roll_until_max(t_data *data, int min, int *max);
void		if_lower_roll_until_min(t_data *data, int *min, int max);
void		insertion_sort_adaptation(t_data *data);
void		bubble_sort(t_data *data);
void		chunk_based_sorting(t_data *data);
void		ft_best_rot(t_stack **stack, t_stack *node);
void		radix_sort(t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_power(int nb, int pow);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);

#endif
