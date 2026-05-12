/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_sort_adaptation_AI.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:04:58 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/11 13:01:17 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

/* ===================== CHECKS ===================== */

static int	is_sorted_desc(t_stack *a)
{
	while (a && a->next)
	{
		if (a->content < a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	stack_size(t_stack *a)
{
	int i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

/* ===================== CREATE LIST ===================== */

static t_stack	*make_list(int *tab, int n)
{
	t_stack *head = NULL;
	t_stack *node;
	int i = 0;

	while (i < n)
	{
		node = ft_lstnew(tab[i]);
		node->next = head;
		head = node;
		i++;
	}
	return (head);
}

/* ===================== TEST RUNNER ===================== */

static int	run_test(char *name, t_stack *a, void (*algo)(t_data *))
{
	t_data *data;
	int size_before;

	data = ft_datanew(a, NULL);
	size_before = stack_size(data->a);

	printf("\n=== %s ===\n", name);

	algo(data);

	if (!is_sorted_desc(data->a))
	{
		printf("❌ NOT SORTED\n");
		return (0);
	}

	if (stack_size(data->a) != size_before)
	{
		printf("❌ LOST ELEMENTS\n");
		return (0);
	}

	if (data->b)
		printf("⚠️ Warning: stack B not empty\n");

	printf("✔️ OK\n");
	return (1);
}

/* ===================== MAIN ===================== */

int	test_insertion_sort_adaptation_AI(void)
{
	int ok = 0;

	/* TEST 1 */
	int t1[] = {54, 128, -128, 500, 396};
	ok += run_test("random case", make_list(t1, 5), insertion_sort_adaptation);

	/* TEST 2 */
	int t2[] = {3, 2, 1};
	ok += run_test("reverse sorted", make_list(t2, 3), insertion_sort_adaptation);

	/* TEST 3 */
	int t3[] = {1, 2, 3, 4, 5};
	ok += run_test("already sorted", make_list(t3, 5), insertion_sort_adaptation);

	/* TEST 4 */
	int t4[] = {42};
	ok += run_test("single element", make_list(t4, 1), insertion_sort_adaptation);

	/* RESULT */
	printf("\n====================\n");
	printf("Tests passed: %d/4\n", ok);
	printf("====================\n");

	return (0);
}
