/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_500_1000.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:21:16 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 13:08:47 by cribstei         ###   ########.fr       */
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

/* ===================== CREATE LIST ===================== */

static t_stack	*make_list(int nbr)
{
	t_stack		*head;
	t_stack		*node;
	int			i;

	i = 0;
	head = NULL;
	srand(time(NULL));
	while (i < nbr)
	{
		node = ft_lstnew(rand());
		node->next = head;
		head = node;
		i++;
	}
	return (head);
}

static int	run_test(char *name, t_stack *a, void (*algo)(t_data *))
{
	t_data	*data;
	int		size_before;
	int		count;

	data = ft_datanew(a, NULL);
	size_before = ft_lstsize(data->a);
	printf("\n=== %s ===\n", name);
	algo(data);
	count = data->count;
	if (!is_sorted(data->a))
	{
		printf("❌ NOT SORTED\n");
		return (0);
	}
	if (ft_lstsize(data->a) != size_before)
	{
		printf("❌ LOST ELEMENTS\n");
		return (0);
	}
	if (data->b)
		printf("⚠️ Warning: stack B not empty\n");
	printf("\n ✔️ OK: liste triee et aucun element perdu\n");
	return (count);
}

int	test_500_1000(void)
{
	t_stack		*list500;
	int			count;

	list500 = make_list(500);

/* 	printf("\n====================\n");
	printf("Algorithme simple:\n");
	printf("====================\n");
	count = run_test("500 valeurs", list500, bubble_sort);
	printf("Nombre d'operation maximum classe n*n : %d\n", 500 * 500);
	if (count > 500 * 500)
		printf("❌ Trop d'operations dude: %d !!\n", count);
	else
		printf("✔️ OK: Bon nombre d'operations: %d !!\n", count); */

	printf("\n====================\n");
	printf("Algorithme medium:\n");
	printf("====================\n");
	count = run_test("500 valeurs", list500, chunk_based_sorting);
	printf("Nombre d'operation maximum classe n*sqrt(n): %d\n",
		500 * ft_square(500));
	if (count > 500 * ft_square(500))
		printf("❌ Trop d'operations dude : %d !!\n", count);
	else
		printf("✔️ OK: Bon nombre d'operations: %d !!\n", count);
	return (0);
}
