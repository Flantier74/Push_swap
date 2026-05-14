/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 13:03:15 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_adaptation(t_data *data)
{
	int	min;
	int	max;

	if (!data->a)
		return ;
	pb(data);
	min = data->b->content;
	max = data->b->content;
	while (data->a_size > 0)
	{
		if (data->a->content < data->b->content)
			if_lower_roll_until_min(data, &min, max);
		if (data->a->content > data->b->content)
			if_upper_roll_until_max(data, min, &max);
		pb(data);
	}
	push_all_b_a(data, min, max);
}
