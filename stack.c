/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:02:09 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/07 13:02:13 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements at the top of stack arr. Do nothing if there is
// only one or no elements.
void	s(int *arr, int arr_size)
{
	int	tmp;

	if (arr_size < 2)
		return;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

void	sa(int *a, int arr_size)
{
	s(a, arr_size);
}

void	sb(int *b, int arr_size)
{
	s(b, arr_size);
}

// sa and sb at the same time.
void	ss(int *a, int *b, int arr_size)
{
	s(a, arr_size);
	s(b, arr_size);
}

// Take the first element at the top of b and put it at the top of a. Do
// nothing if b is empty.
void	p(int *a, int *b, int arr_size)
{
	revr(a, arr_size);
	a[0] = b[0];
	r(b, arr_size);
}

void pa(int *a, int *b, int arr_size)
{
	p(a, b, arr_size);
}

void pb(int *b, int *a, int arr_size)
{
	p(b, a, arr_size);
}

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	r(int *arr, int arr_size)
{
	int	tmp;

	tmp = arr[arr_size - 1];
	while (arr_size - 1)
	{
		arr[arr_size - 1] = arr[arr_size - 2];
		arr_size--;
	}
	arr[0] = tmp;
}

void	ra(int *a, int arr_size)
{
	r(a, arr_size);
}

void	rb(int *b, int arr_size)
{
	r(b, arr_size);
}

// ra and rb at the same time.
void	rr(int *a, int *b, int arr_size)
{
	ra(a, arr_size);
	rb(b, arr_size);
}

// Shift down all elements of stack arr by one.
// The last element becomes the first one.
void	revr(int *arr, int arr_size)
{
	int	i;

	i = arr_size;
	while (i-- > 1)
		r(arr, arr_size);
}

void	rra(int *a, int arr_size)
{
	revr(a, arr_size);
}

void	rrb(int *b, int arr_size)
{
	revr(b, arr_size);
}

void	rrr(int *a, int *b, int arr_size)
{
	rra(a, arr_size);
	rrb(b, arr_size);
}
