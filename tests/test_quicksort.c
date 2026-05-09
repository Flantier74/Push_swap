/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:03 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/09 16:23:48 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

int test_quicksort(void)
{
	t_data  *data = malloc(sizeof(t_data));
	t_stack *stack_a = init_stack(12, 5, 0, 79, -1, 42);
	t_stack *stack_b = init_stack(0, 0, 0, 0, 0, 0);
	data->a = stack_a;
	data->b = stack_b;

	printf("\n###   TEST quicksort()   "
	       "#######################################################\n");
	printer(data);
	quicksort(stack_a, 6, sizeof(t_stack), ascending);
	printer(data);
	// quicksort(stack_b, 6, sizeof(t_stack), descending);
	// printer(data);

	return (-1);
}
