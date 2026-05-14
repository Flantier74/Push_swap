/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_adaptation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:57:24 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 11:22:47 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_b_a(t_data *data, int min, int max)
{
	while (data->b->content != max)
		rb(data);
	while (data->b)
	{
		printf("hello");
		pa(data);
		rrb(data);
	}
	while (data->a->content != min)
		ra(data);
}

static void	if_upper_roll_until_max(t_data *data, int min, int *max)
{
	int	side;

	if (data->a->content > *max)
	{
		while(data->b->content != *max)
			rb(data);
		rb(data);
		*max = data->a->content;
		return ;
	}
	side = 0;
	if(data->a->content > (*max + min) / 2)
		side = 1;
	if(side)
	{
		while (data->a->content > data->b->content)
			rb(data);
	}
	else
	{
		while (data->a->content > data->b->content)
			rrb(data);
		while (data->a->content < data->b->content)
			rrb(data);
		rb(data);
	}
}

static void	if_lower_roll_until_min(t_data *data, int *min, int max)
{
	int	side;

	if (data->a->content < *min)
	{
		while(data->b->content != *min)
			rb(data);
		*min = data->a->content;
		return ;
	}
	side = 0;
	if(data->a->content > (max + *min) / 2)
		side = 1;
	if(side)
	{
		while (data->a->content < data->b->content)
			rrb(data);
		rb(data);
	}
	else
	{
		while (data->a->content < data->b->content)
			rb(data);
		while (data->a->content > data->b->content)
			rb(data);
	}
}

void	insertion_sort_adaptation(t_data *data)
{
	int	min;
	int	max;
	int	i;

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
	i = 0;
	while (i++ < data->a_size)
	{
		printf("%d, ", data->a->content);
		ra(data);
	}
}
