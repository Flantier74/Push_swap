/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_stack_a_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:21:21 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 17:24:20 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_upper_roll_until_max(t_data *data, int min, int *max)
{
	if (data->b->content > *max)
	{
		while (data->a->content != *max)
			ra(data);
		ra(data);
		*max = data->b->content;
		return ;
	}
	if (data->b->content > (*max + min) / 2)
	{
		while (data->b->content > data->a->content)
			ra(data);
	}
	else
	{
		while (data->b->content > data->a->content)
			rra(data);
		while (data->b->content < data->a->content)
			rra(data);
		ra(data);
	}
}

void	if_lower_roll_until_min(t_data *data, int *min, int max)
{
	if (data->b->content < *min)
	{
		while (data->a->content != *min)
			ra(data);
		*min = data->b->content;
		return ;
	}
	if (data->b->content > (max + *min) / 2)
	{
		while (data->b->content < data->a->content)
			rra(data);
		ra(data);
	}
	else
	{
		while (data->b->content < data->a->content)
			ra(data);
		while (data->b->content > data->a->content)
			ra(data);
	}
}

void	ss(t_data *data)
{
	int	tmp;

	if (!data->a || !data->a->next || !data->b || !data->b->next)
		return ;
	tmp = data->a->content;
	data->a->content = data->a->next->content;
	data->a->next->content = tmp;
	tmp = data->b->content;
	data->b->content = data->b->next->content;
	data->b->next->content = tmp;
	data->count += write(1, "ss", 2) - 1;
}

void	rr(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->a || !data->a->next || !data->b || !data->b->next)
		return ;
	tmp = data->a;
	last = ft_lstlast(data->a);
	data->a = data->a->next;
	last->next = tmp;
	tmp->next = NULL;
	tmp = data->b;
	last = ft_lstlast(data->b);
	data->b = data->b->next;
	last->next = tmp;
	tmp->next = NULL;
	data->count += write(1, "rr", 2) - 1;
}

void	rrr(t_data *data)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!data->a || !data->a->next || !data->b || !data->b->next)
		return ;
	last = ft_lstlast(data->a);
	penultimate = ft_lstpenultimate(data->a);
	penultimate->next = NULL;
	last->next = data->a;
	data->a = last;
	last = ft_lstlast(data->b);
	penultimate = ft_lstpenultimate(data->b);
	penultimate->next = NULL;
	last->next = data->b;
	data->b = last;
	data->count += write(1, "rrr", 3) - 2;
}
