/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:33:02 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/15 11:37:22 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_chunk(t_data *data, int chunk, int min_chunk)
{
	int	i;
	int	min_current;
	int	max_current;

	min_current = ft_min(data->a);
	max_current = ft_max(data->a);
	i = 0;
	while (data->b && i < data->a_size + data->b_size)
	{
		if (data->b->content > min_chunk + chunk)
			rb(data);
		else
		{
			if (data->b->content < data->a->content)
				if_lower_roll_until_min(data, &min_current, max_current);
			if (data->b->content > data->a->content)
				if_upper_roll_until_max(data, min_current, &max_current);
			pa(data);
		}
		i++;
	}
}

void	chunk_based_sorting(t_data *data)
{
	int		chunk;
	int		min;
	int		min_chunk;
	int		max_all;

	if (!data->a)
		return ;
	init_rank(data->a);
	push_all_ab_let_one(data);
	min_chunk = ft_min(data->b);
	max_all = ft_max(data->b);
	chunk = (max_all - min_chunk) / ft_square(data->b_size);
	if (chunk < 0)
		chunk = -chunk;
	while (data->b && min_chunk <= max_all)
	{
		loop_chunk(data, chunk, min_chunk);
		min_chunk = min_chunk + chunk;
	}
	min = ft_min(data->a);
	while (data->a->content != min)
		ra(data);
}
