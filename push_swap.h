/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:55 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 14:35:22 by cribstei         ###   ########.fr       */
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
void		push_all_b_a(t_data	*data, int *count);
int			ft_square(double value);
int			ft_max(t_stack *stack);
int			ft_min(t_stack *stack);
void		quicksort(t_stack *stack, size_t nmemb, size_t size, int (*compar)(const int *, const int *));
void		insertion_sort_adaptation(t_data *data);
void		chunk_based_sorting(t_data *data);
void		swap(int *a, int *b);
void		ft_best_rot(t_stack **stack, t_stack *node);
void		radix_sort(t_data *data);

#endif
