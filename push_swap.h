/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:03:15 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/07 13:03:16 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

void	s(int *arr, int arr_size);
void	sa(int *a, int arr_size);
void	sb(int *b, int arr_size);
void	ss(int *a, int *b, int arr_size);
void    p(int *a, int *b, int arr_size);
void	pa(int *a, int *b, int arr_size);
void	pb(int *b, int *a, int arr_size);
void	r(int *arr, int arr_size);
void	ra(int *a, int arr_size);
void	rb(int *b, int arr_size);
void	rr(int *a, int *b, int arr_size);
void    revr(int *arr, int arr_size);
void	rra(int *a, int arr_size);
void	rrb(int *b, int arr_size);
void	rrr(int *a, int *b, int arr_size);

void	quicksort(void *list, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void	swap(int *a, int *b);

#endif
