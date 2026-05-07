/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/07 17:44:10 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*insertion_sort_adaptation(int *a, int *b, int a_size, int b_size)
{
	pb(a, b, a_size, b_size);
	a_size--;
	b_size++;

	while (size_a > 0)
	{
		while (a[0] > b[0] && i < size_a)
			rrb(a, a_size);
		if (a[0] < b[0])
			pb(a, b, a_size, b_size);
		else
		{
			rb(a, a_size);
			pb(a, b, a_size, b_size);
		}
		a_size--;
		b_size++;
	}
}

/* int	main(void)
{
	int		i;
	size_t	n;
	int		tab[] = {9, 8, 7, 6, 1, 2, -1, 0};

	n = 8;
	insertion_sort_adaptation(tab);
	i = 0;
	while (i < n)
	{
		printf("%d, ", tab[i])
		i++;
	}
} */
