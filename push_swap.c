/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:23:06 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/14 10:53:21 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void printer(t_data *data)
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

static int select_strategy(char **argv)
{
	if (!ft_strncmp("--simple", argv[1], 8))
		return (1);
	else if (!ft_strncmp("--medium", argv[1], 8))
		return (2);
	else if (!ft_strncmp("--complex", argv[1], 9))
		return (3);
	else if (!ft_strncmp("--adaptative", argv[1], 12))
		return (0);
	return (-1);
}

static void sort(t_data *data, int strat)
{
	if (strat == 1)
	{
		printf("\nSIMPLE\n");
		insertion_sort_adaptation(data);
		return ;
		// return (insertion_sort_adaptation(data));
	}
	else if (strat == 2)
	{
		printf("\nMEDIUM\n");
		chunk_based_sorting(data);
		return ;
		// return (chunk_based_sorting(data));
	}
	else if (strat == 3)
	{
		printf("\nCOMPLEX\n");
		radix_sort(data);
		return ;
	}
	else
		return ; // TODO adaptive()
}

static t_data *build_data(int argc, char **argv, int strat)
{
	t_data  *data;
	t_stack *stack_a;
	t_stack *ptr;

	if (argc < 1 || !argv)
		return (NULL);
	data = malloc(sizeof(t_data));
	stack_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc--;
	data->a = stack_a;
	ptr = stack_a;
	while (argc > (1 + (strat > 0)))
	{
		ptr->next = ft_lstnew(ft_atoi(argv[argc - 1]));
		ptr = ptr->next;
		argc--;
	}
	return (data);
}

int main(int argc, char *argv[])
{
	int     strat;
	t_data	*data;
	double	disorder;

	strat = select_strategy(argv);
	data = build_data(argc, argv, strat);
	disorder = calc_disorder(data->a);

	sort(data, strat);
	printer(data);
	printf("------------------> OPS(disorder) = %d(%f)\n", data->count,
	       disorder);

	return (0);
}
