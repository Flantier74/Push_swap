/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:20:17 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/18 13:24:32 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	if (*lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
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

int	dupplicate_values(t_stack *stack)
{
	t_stack		*first;
	t_stack		*to_compare;

	first = stack;
	to_compare = stack;
	while (to_compare && to_compare->next)
	{
		stack = first;
		while (stack)
		{
			if (stack == to_compare)
				stack = stack->next;
			if (to_compare->content == stack->content)
				return (1);
			stack = stack->next;
		}
		to_compare = to_compare->next;
	}
	return (0);
}
