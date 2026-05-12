/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_sort_adaptation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:49:48 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/11 12:56:28 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

int	test_insertion_sort_adaptation(void)
{
	t_data	*data;
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*third_a;
	t_stack	*fourth_a;
	t_stack	*fifth_a;
	t_stack	*tmp;

	first_a = ft_lstnew(54);
	second_a = ft_lstnew(128);
	third_a = ft_lstnew(-128);
	fourth_a = ft_lstnew(500);
	fifth_a = ft_lstnew(396);

	first_a->next = second_a;
	second_a->next = third_a;
	third_a->next = fourth_a;
	fourth_a->next = fifth_a;

	data = ft_datanew(first_a, NULL);

	printf("Stack A BEFORE:\n");
	tmp = data->a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}

	printf("\nStack B BEFORE:\n");
	tmp = data->b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}

	insertion_sort_adaptation(data);

	printf("\nSTACK A AFTER:\n");
	tmp = data->a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}

	printf("\nSTACK B AFTER:\n");
	tmp = data->b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}

	/* IMPORTANT: ajout d’un check minimal */
	tmp = data->a;
	while (tmp && tmp->next)
	{
		if (tmp->content < tmp->next->content)
		{
			printf("❌ NOT SORTED DESC\n");
			return (0);
		}
		tmp = tmp->next;
	}

	printf("✔ OK\n");

	return (0);
}
