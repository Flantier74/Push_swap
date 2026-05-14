/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:20:17 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 13:21:03 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack);
}

// gives each node of the stack a rank based on its value compared to other
// nodes value.
void	init_rank(t_stack *stack)
{
	t_stack	*node_min;
	int		next_rank;
	t_stack	*current;

	node_min = stack;
	next_rank = ft_lstsize(stack);
	while (next_rank > 0)
	{
		current = stack;
		while (current->rank)
			current = current->next;
		node_min = current;
		current = stack;
		while (current)
		{
			if (current->content < node_min->content && !current->rank)
				node_min = current;
			current = current->next;
		}
		node_min->rank = next_rank;
		next_rank--;
	}
}
