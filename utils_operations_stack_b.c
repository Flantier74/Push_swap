/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_stack_b.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophe <christophe@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:24:27 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 23:08:32 by christophe       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *data)
{
	int	tmp;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b->content;
	data->b->content = data->b->next->content;
	data->b->next->content = tmp;
	data->count += write(1, "sb ", 3) - 1;
}

void	pb(t_data *data)
{
	t_stack	*tmp;

	if (!data->a)
		return ;
	tmp = data->a;
	if (data->a->next)
		data->a = data->a->next;
	else
		data->a = NULL;
	tmp->next = data->b;
	data->b = tmp;
	data->a_size--;
	data->b_size++;
	data->count += write(1, "pb ", 3) - 1;
}

void	rb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	last = ft_lstlast(data->b);
	data->b = data->b->next;
	last->next = tmp;
	tmp->next = NULL;
	data->count += write(1, "rb ", 3) - 1;
}

void	rrb(t_data *data)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!data->b || !data->b->next)
		return ;
	last = ft_lstlast(data->b);
	penultimate = ft_lstpenultimate(data->b);
	penultimate->next = NULL;
	last->next = data->b;
	data->b = last;
	data->count += write(1, "rrb ", 4) - 2;
}
