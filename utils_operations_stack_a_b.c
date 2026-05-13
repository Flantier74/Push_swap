/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_stack_a_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:21:21 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 14:31:19 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	/* data->count += write(1, "ss", 2) - 1; */
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	/* data->count += write(1, "rr", 2) - 1; */
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	/* data->count += write(1, "rrr", 2) - 2; */
}
