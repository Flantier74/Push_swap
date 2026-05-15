/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:35:04 by cribstei          #+#    #+#             */
/*   Updated: 2026/05/15 15:40:51 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	roll_in_good_direction(t_data *data, int i, int size)
{
	if (i > size / 2)
	{
		while (i++ < size)
			rra(data);
	}
	else
	{
		while (i-- >= 0)
			ra(data);
	}
}

static int	sorted_but_not_rolled(t_data *data)
{
	int			i;
	int			size;
	t_stack		*ptr;

	i = 0;
	ptr = data->a;
	size = ft_lstsize(data->a);
	while (ptr && ptr->next && ptr->content < ptr->next->content && i++)
		ptr = ptr->next;
	if (i == size - 1)
		return (1);
	else
		ptr = ptr->next;
	while (ptr && ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	if (ptr->content > data->a->content)
		return (0);
	roll_in_good_direction(data, i, size);
	return (1);
}

void	bubble_sort(t_data *data)
{
	int			i;
	int			sorted;

	sorted = is_sorted(data->a);
	while (!sorted)
	{
		i = 0;
		while (i < data->a_size)
		{
			if (i < data->a_size - 1 && data->a->next
				&& data->a->content > data->a->next->content)
			{
				sa(data);
				if (sorted_but_not_rolled(data))
					return ;
			}
			ra(data);
			i++;
		}
		sorted = is_sorted(data->a);
	}
}
