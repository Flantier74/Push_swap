/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_sort_adaptation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:49:48 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/10 14:29:24 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_test.h"

int	test_insertion_sort_adaptation(void)
{
	t_data	*data;
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*third_a;
	t_stack	*first_b;
	t_stack	*fourth_a;
	t_stack	*fifth_a;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	first_a = ft_lstnew(54);
	second_a = ft_lstnew(128);
	third_a = ft_lstnew(-128);
	fourth_a = ft_lstnew(500);
	fifth_a = ft_lstnew(396);
	first_a->next = second_a;
	second_a->next = third_a;
	third_a->next = fourth_a;
	fourth_a->next = fifth_a;
	first_b = NULL;
	data = ft_datanew(first_a, first_b);

	printf("Stack A:\n");
	tmp_a = data->a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}

	printf("\nStack B:\n");
	tmp_b = data->b;
	while (tmp_b)
	{
		printf("%d\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}

	insertion_sort_adaptation(data);

	printf("\nMAJ stack A:\n");
	tmp_a = data->a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("\nMAJ stack B:\n");
	tmp_b = data->b;
	while (tmp_b)
	{
		printf("%d\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}
	return (0);
}
