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

#include "../test_utils.h"

#include "../push_swap.h"

t_stack *init_stack(int a, int b, int c, int d, int e, int f)
{
	t_stack *new;
	t_stack *stack = malloc(sizeof(t_stack));

	stack = ft_lstnew(a);
	new = ft_lstnew(b);
	new->next = ft_lstnew(c);
	new = new->next;
	new->next = ft_lstnew(d);
	new = new->next;
	new->next = ft_lstnew(e);
	new = new->next;
	new->next = ft_lstnew(f);

	return (stack);
}

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
