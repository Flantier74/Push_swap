/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:33:02 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 14:35:37 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(t_data *data)
{
	int			i;
	int			sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < data->b_size)
		{
			if (i < data->b_size - 1 && data->b->next
				&& data->b->content < data->b->next->content)
			{
				sb(data);
				sorted = 0;
			}
			rb(data);
			i++;
		}
	}
}

static void	loop_chunk(t_data *data, int chunk, int min)
{
	int	i;

	i = 0;
	while (data->a && i < data->a_size + data->b_size)
	{
		if (data->a->content > min + chunk)
			ra(data);
		else
			pb(data);
		i++;
	}
}

void	chunk_based_sorting(t_data *data)
{
	int		chunk;
	int		min;
	int		max;

	min = ft_min(data->a);
	max = ft_max(data->a);
	chunk = (max - min) / ft_square(data->a_size);
	if (chunk < 0)
		chunk = -chunk;
	while (data->a && min < max)
	{
		loop_chunk(data, chunk, min);
		bubble_sort(data);
		min = min + chunk;
	}
	push_all_b_a(data);
}
