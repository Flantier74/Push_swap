/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:37:34 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 13:20:51 by cribstei         ###   ########.fr       */
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
