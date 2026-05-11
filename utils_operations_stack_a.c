/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_stack_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:21:13 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/10 14:28:20 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a->content;
	data->a->content = data->a->next->content;
	data->a->next->content = tmp;
}

void	pa(t_data *data)
{
	t_stack	*tmp;

	if (!data->b)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->a;
	data->a = tmp;
}

void	ra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	last = ft_lstlast(data->a);
	data->a = data->a->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rra(t_data *data)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!data->a || !data->a->next)
		return ;
	last = ft_lstlast(data->a);
	penultimate = ft_lstpenultimate(data->a);
	penultimate->next = NULL;
	last->next = data->a;
	data->a = last;
}
