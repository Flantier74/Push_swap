/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/10 14:22:45 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_change_size(t_data *data)
{
	pb(data);
	data->a_size--;
	data->b_size++;
}

void	insertion_sort_adaptation(t_data *data)
{
	int	i;
	int	min;

	pb_change_size(data);
	min = data->b->content;
	while (data->a_size > 0)
	{
		i = 0;
		while (data->a->content > data->b->content && i++ < data->b_size)
			rb(data);
		if (data->a->content < data->b->content)
		{
			pb_change_size(data);
			if (data->b->content < min)
				min = data->b->content;
		}
		else
		{
			pb_change_size(data);
			rb(data);
		}
		while (data->b->content != min)
			rb(data);
	}
}
