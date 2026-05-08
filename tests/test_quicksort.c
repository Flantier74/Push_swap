/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:03 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/08 16:29:05 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_utils.h"

void quicksort(void *list, size_t nmemb, size_t size,
               int (*compar)(const void *, const void *));


int test_quicksort(void)
{
	int  arr[] = {5, 12, -1, 7, 0, 7, 4, 2};
	int *b = malloc(1 * sizeof(int));

	printf("\n###   TEST quicksort()   "
	       "#######################################################\n");
	printer(arr, b, 0, 8);
	quicksort(arr, 8, sizeof(int), ascending);
	printer(arr, b, 0, 8);
	quicksort(arr, 8, sizeof(int), descending);
	printer(arr, b, 0, 8);

	return (-1);
}
