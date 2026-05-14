/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:35:04 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/14 16:29:42 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_data *data)
{
	int			i;
	int			sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < data->a_size)
		{
			if (i < data->a_size - 1 && data->a->next
				&& data->a->content > data->a->next->content)
			{
				sa(data);
				sorted = 0;
			}
			ra(data);
			i++;
		}
	}
	/* i = 0;
	while (i++ < data->a_size)
	{
		printf("%d, ", data->a->content);
		ra(data);
	} */
}
