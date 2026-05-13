/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:13:10 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/13 12:52:11 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n >>= 1;
		count++;
	}
	return (count);
}

static int	highest_rank(t_data *data)
{
	t_stack	*p;
	int		max;

	max = 0;
	p = data->a;
	while (p)
	{
		if (p->rank >= max)
			max = p->rank;
		p = p->next;
	}
	return (max);
}

int	check_rank_last_bit(t_data *data, int bitshift)
{
	int	ops;

	ops = 0;
	if (((data->a->rank >> bitshift) & 1) == 0)
	{
		pb(data);
		ops++;
		write(1, "pb\n", 3);
	}
	else
	{
		ra(data);
		ops++;
		write(1, "ra\n", 3);
	}
	return (ops);
}

int	check_rank_before_last_bit(t_data *data, int bitshift)
{
	int	ops;

	ops = 0;
	if (((data->b->rank >> (1 + bitshift)) & 1) == 1)
	{
		pa(data);
		ops++;
		write(1, "pa\n", 3);
	}
	else
	{
		rb(data);
		ops++;
		write(1, "rb\n", 3);
	}
	return (ops);
}

int	radix_sort(t_data *data)
{
	int	ops;
	int	lst_size;
	int	bitshift;
	int	max_rank;

	ops = 0;
	bitshift = 0;
	init_rank(data->a);
	max_rank = highest_rank(data);
	while (bitshift <= count_bits(max_rank))
	{
	  lst_size = ft_lstsize(data->a);
		while (lst_size)
		{
			ops += check_rank_last_bit(data, bitshift);
			lst_size--;
		}
		lst_size = ft_lstsize(data->b);
		while (lst_size)
		{
			ops += check_rank_before_last_bit(data, bitshift);
			lst_size--;
		}
		bitshift++;
	}
	return (ops);
}
