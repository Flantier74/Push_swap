/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:23:06 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/15 13:34:02 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printer(t_data *data)
{
	t_stack	*a;
	t_stack	*b;

	a = data->a;
	b = data->b;
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

static int	select_strategy(char **argv)
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

static int	adapt(double disorder)
{
	if (disorder < 0.2)
		return (1);
	else if (disorder < 0.5)
		return (2);
	else
		return (3);
}

static void	sort(t_data *data, int strat)
{
	if (strat == 1)
		return (write(1, "\nSIMPLE\n", 8), bubble_sort(data));
	else if (strat == 2)
		return (write(1, "\nMEDIUM\n", 8), chunk_based_sorting(data));
	else if (strat == 3)
		return (write(1, "\nCOMPLEX\n", 9), radix_sort(data));
	else
	{
		sort(data, adapt(strat));
		return ;
	}
}

static t_data	*build_data(int argc, char **argv, int strat)
{
	t_stack		*ptr;
	t_stack		*first;
	int			i;

	str_overflow(argv[argc - 1]);
	if (argc < 1 || !argv || strat < 0)
		return (NULL);
	i = 2;
	first = ft_lstnew(ft_atoi(argv[i++]));
	ptr = first;
	while (i < argc)
	{
		ptr->next = ft_lstnew(ft_atoi(argv[i]));
		ptr = ptr->next;
		i++;
	}
	return (ft_datanew(first, NULL));
}

int	main(int argc, char *argv[])
{
	int		strat;
	t_data	*data;
	double	disorder;

	if (argc < 1 || !argv[1])
	{
		write(2, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	strat = select_strategy(argv);
	data = build_data(argc, argv, strat);
	disorder = calc_disorder(data->a);
	sort(data, strat);
	printer(data);
	printf("------------------> OPS(disorder) = %d(%f)\n", data->count,
		disorder);
	return (0);
}
