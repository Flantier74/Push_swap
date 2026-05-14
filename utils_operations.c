/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:24:27 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 17:18:47 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_square(double value)
{
	double	square;

	square = value / 2;
	while (square * square / value < 0.98 || 1.02 < square * square / value)
		square = 0.5 * (square + value / square);
	return ((int)square);
}

int	ft_min(t_stack *stack)
{
	int	min;

	if (stack)
		min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_stack *stack)
{
	int	max;

	if (stack)
		max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

void	push_all_ab_let_one(t_data *data)
{
	if (!data->a)
		return ;
	while (data->a->next)
		pb(data);
}
