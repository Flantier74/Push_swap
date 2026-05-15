/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_stack_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:21:13 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/15 11:23:30 by cribstei         ###   ########.fr       */
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
	data->count += write(1, "sa\n", 3) - 2;
	data->count_sa += 1;
}

void	pa(t_data *data)
{
	t_stack	*tmp;

	if (!data->b)
		return ;
	tmp = data->b;
	if (data->b->next)
		data->b = data->b->next;
	else
		data->b = NULL;
	tmp->next = data->a;
	data->a = tmp;
	data->a_size++;
	data->b_size--;
	data->count += write(1, "pa\n", 3) - 2;
	data->count_pa += 1;
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
	data->count += write(1, "ra\n", 3) - 2;
	data->count_ra += 1;
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
	data->count += write(1, "rra\n", 4) - 3;
	data->count_rra += 1;
}
