/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/13 14:26:58 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_adaptation(t_data *data)
{
	int	i;
	int	max;

	pb(data);
	max = data->b->content;
	while (data->a_size > 0)
	{
		i = 0;
		while (data->a->content < data->b->content && i++ < data->b_size)
			rb(data);
		if (data->a->content > data->b->content)
		{
			pb(data);
			if (data->b->content > max)
				max = data->b->content;
		}
		else
		{
			pb(data);
			rb(data);
		}
	}
	while (data->b->content != max)
		rb(data);
	push_all_b_a(data);
}
