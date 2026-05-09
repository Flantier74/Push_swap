/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:01:00 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/07 13:01:49 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void pswap()
{
}

// STACK = the stack to sort
// NMEMB = the number of element in stack
// SIZE = the size in bytes of a single element
void quicksort(t_stack *stack, size_t nmemb, size_t size,
               int (*compar)(const int, const int))
{
	t_stack *i;
	t_stack *j;
	t_stack *p;

	i = stack - size;
	j = stack;
	p = stack + ((nmemb - 1) * size);

	while (j < p)
	{
		if (compar(j->content, p->content))
			j += size;
		else
		{
			swap(&p->content, &j->content);
			i += size;
			j += size;
		}
	}
	if (nmemb > 1)
		quicksort(stack, nmemb - 1, size, compar);
}
