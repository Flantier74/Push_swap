/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:33:02 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 12:59:21 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_chunk(t_data *data, int chunk, int min_chunk)
{
	int	i;
	int	min_current;
	int	max_current;

	if (!data->b)
		pb(data);
	min_current = ft_min(data->b);
	max_current = ft_max(data->b);
	i = 0;
	while (data->a && i < data->a_size + data->b_size)
	{
		if (data->a->content > min_chunk + chunk)
			ra(data);
		else
		{
			if (data->a->content < data->b->content)
				if_lower_roll_until_min(data, &min_current, max_current);
			if (data->a->content > data->b->content)
				if_upper_roll_until_max(data, min_current, &max_current);
			pb(data);
		}
		i++;
	}
}

void	chunk_based_sorting(t_data *data)
{
	int		chunk;
	int		min_chunk;
	int		max_all;
	int		i;

	min_chunk = ft_min(data->a);
	max_all = ft_max(data->a);
	chunk = (max_all - min_chunk) / ft_square(data->a_size);
	if (chunk < 0)
		chunk = -chunk;
	while (data->a && min_chunk < max_all)
	{
		loop_chunk(data, chunk, min_chunk);
		min_chunk = min_chunk + chunk;
	}
	push_all_b_a(data, ft_min(data->b), max_all);
	i = 0;
	while (i++ < data->a_size)
	{
		printf("%d, ", data->a->content);
		ra(data);
	}
}
