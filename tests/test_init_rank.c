/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_rank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:23:36 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/09 16:23:37 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

int test_init_rank(void)
{
	t_data  *data = malloc(sizeof(t_data));
	t_stack *stack_a = init_stack(-12, 5, 0, 79, -1, 42);
	t_stack *stack_b = init_stack(0, 0, 0, 0, 0, 0);
	data->a = stack_a;
	data->b = stack_b;

	init_rank(stack_a);
	printer(data);
	while (stack_a)
	{
		printf("%d	", stack_a->rank);
		stack_a = stack_a->next;
	}
	return (0);
}
