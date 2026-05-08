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

void quicksort(void *list, size_t nmemb, size_t size,
               int (*compar)(const void *, const void *))
{
	void *i;
	void *j;
	void *p;

	i = list - size;
	j = list;
	p = list + ((nmemb - 1) * size);

	while (j < p)
	{
		if (compar(j, p))
			j += size;
		else
		{
			swap(p, j);
			i += size;
			j += size;
		}
	}
	if (nmemb > 1)
		quicksort(list, nmemb - 1, size, compar);
}
