/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:19:49 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/15 13:20:01 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_overflow(long sum, int sign, char *nptr, int len)
{
	if (((long)sum + ((long)(*nptr - 48) *(long)ft_power(10, len - 1)))
		<= ((2147483647 + (long)(sign < 0))))
		return (1);
	else
		return (error_exit(), 1);
}

int	error_exit(void)
{
	write(2, "Error\n", 6);
	return (exit(EXIT_FAILURE), -1);
}
