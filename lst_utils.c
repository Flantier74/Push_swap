/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:37:34 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/15 11:30:05 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_datanew(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = a;
	data->b = b;
	data->a_size = ft_lstsize(a);
	data->b_size = ft_lstsize(b);
	data->count = 0;
	data->count_sa = 0;
	data->count_sb = 0;
	data->count_ss = 0;
	data->count_pa = 0;
	data->count_pb = 0;
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rr = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
	data->count_rrr = 0;
	return (data);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	return (ft_lstlast(stack->next));
}

t_stack	*ft_lstpenultimate(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next->next)
		return (stack);
	return (ft_lstpenultimate(stack->next));
}

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->rank = 0;
	stack->next = NULL;
	return (stack);
}
