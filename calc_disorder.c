/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_disorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:45:36 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/13 12:45:38 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->content > j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
