/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 17:17:20 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_adaptation(t_data *data)
{
	int	min;
	int	max;

	if (!data->a)
		return ;
	init_rank(data->a);
	push_all_ab_let_one(data);
	min = data->a->content;
	max = data->a->content;
	while (data->b_size > 0)
	{
		if (data->b->content < data->a->content)
			if_lower_roll_until_min(data, &min, max);
		if (data->b->content > data->a->content)
			if_upper_roll_until_max(data, min, &max);
		pa(data);
	}
	while (data->a->content != min)
		ra(data);
}
