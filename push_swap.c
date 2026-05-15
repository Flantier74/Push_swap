/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:23:06 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/15 17:01:33 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (bubble_sort(data));
	else if (strat == 2)
		return (chunk_based_sorting(data));
	else if (strat == 3)
		return (radix_sort(data));
	else
	{
		sort(data, adapt(calc_disorder(data->a)));
		return ;
	}
}

static t_data	*build_data(int argc, char **argv, int strat)
{
	t_data	*data;
	t_stack	*ptr;
	int		i;

	str_overflow(argv[1 + (strat >= 0)]);
	if (argc < 1 || !argv)
		error_exit();
	data = ft_datanew(ft_lstnew(ft_atoi(argv[1 + (strat >= 0)])), NULL);
	argc--;
	ptr = data->a;
	i = 1 + (strat >= 0);
	while (i < argc)
	{
		str_overflow(argv[i + 1]);
		ptr->next = ft_lstnew(ft_atoi(argv[i + 1]));
		ptr = ptr->next;
		i++;
	}
	data->a_size = ft_lstsize(data->a);
	return (data);
}

int	main(int argc, char *argv[])
{
	int		strat;
	t_data	*data;

	if (argc < 1 || !argv[1])
		error_exit();
	strat = select_strategy(argv);
	if (((strat >= 0) && (select_strategy(argv + 1) >= 0))
		|| (argc == 2 && strat > 0))
		error_exit();
	data = build_data(argc, argv, strat);
	sort(data, strat);
	ft_lstclear(&data->a);
	ft_lstclear(&data->b);
	free(data);
	return (0);
}
