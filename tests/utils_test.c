/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:23 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/08 16:29:25 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

#include "../push_swap.h"

t_stack *init_stack(int a, int b, int c, int d, int e, int f)
{
	t_stack *new;
	t_stack *stack = malloc(sizeof(t_stack));

	stack = ft_lstnew(a);
	new = ft_lstnew(b);
	stack->next = new;
	new->next = ft_lstnew(c);
	new = new->next;
	new->next = ft_lstnew(d);
	new = new->next;
	new->next = ft_lstnew(e);
	new = new->next;
	new->next = ft_lstnew(f);

	return (stack);
}

// print stacks in data
void printer(t_data *data)
{
	t_stack *a = data->a;
	t_stack *b = data->b;

	printf("   AAA      BBB\n------------------\n");
	while (a || b)
	{
		if (a)
		{
			printf("(%d) %3d         ", a->rank, a->content);
			a = a->next;
		}
		if (b)
		{
			printf("(%d) %3d", b->rank, b->content);
			b = b->next;
		}
		printf("\n");
	}
}

int ascending(const int *a, const int *b)
{
	return (*a <= *b);
}

int descending(const int *a, const int *b)
{
	return (*b <= *a);
}
