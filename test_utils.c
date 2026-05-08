/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:23 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/08 16:29:25 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.h"

// print array A, if N == 2, also prints B. Arrays must be of size SIZE
void printer(int *a, int *b, int n, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d,", a[i]);
	printf("\n");

	if (n == 2)
	{
		for (int i = 0; i < size; i++)
			printf("%d,", b[i]);
		printf("\n");
	}
}

int ascending(const void *a, const void *b)
{
	return (*(int *)a <= *(int *)b);
}

int descending(const void *a, const void *b)
{
	return (*(int *)b <= *(int *)a);
}
