/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chunk_based_sorting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:26:12 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 11:22:49 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

/* ===================== CHECKS ===================== */

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
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
	t_stack		*head;
	t_stack		*node;
	int			i;

	i = 0;
	head = NULL;
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
	t_data	*data;
	int		size_before;

	data = ft_datanew(a, NULL);
	size_before = stack_size(data->a);
	printf("\n=== %s ===\n", name);
	algo(data);
	if (!is_sorted(data->a))
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

int	test_chunk_based_sorting(void)
{
	int	ok;

	ok = 0;
	/* TEST 1 */
	int t1[] = {54, 128, -128, 500, 396, 10, 25, 46, -99, 120, 0, 2, -1, -2, -45, 25, 555};
	ok += run_test("random case", make_list(t1, 17), chunk_based_sorting);
	/* TEST 2 */
	int t2[] = {3, 2, 1};
	ok += run_test("reverse sorted", make_list(t2, 3), chunk_based_sorting);
	/* TEST 3 */
	int t3[] = {1, 2, 3, 4, 5};
	ok += run_test("already sorted", make_list(t3, 5), chunk_based_sorting);
	/* TEST 4 */
	int t4[] = {42};
	ok += run_test("single element", make_list(t4, 1), chunk_based_sorting);
	/* RESULT */
	printf("\n====================\n");
	printf("Tests passed: %d/4\n", ok);
	printf("====================\n");
	return (0);
}
