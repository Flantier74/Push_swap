/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:33:02 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/11 16:09:56 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_chunk(t_data *data, int nbr, int min)
{
	int	i;

	i = 0;
	while (data->a && i < data->a_size)
	{
		if (data->a->content > min + nbr)
			ra(data);
		else
			pb(data);
		i++;
	}
}

void	chunk_based_sorting(t_data *data)
{
	int		square;
	int		nbr;
	int		min;
	int		max;

	square = ft_square(data->a_size);
	min = ft_min(data->a);
	max = ft_max(data->a);
	nbr = (max - min) / square;
	if (nbr < 0)
		nbr = -nbr;
	while (data->a && min < max)
	{
		loop_chunk(data, nbr, min);
		bubble_sort(data);
		min = min + nbr;
	}
	push_all_b_a(data);
	while (data->b)
	{
		printf("%d\n", data->b->content);
		data->b = data->b->next;
	}
}
