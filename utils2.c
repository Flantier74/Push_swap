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

int	str_overflow(char *str)
{
	if ((ft_atoi(str) < -2147483649) || (ft_atoi(str) > 2147483648))
		return (error_exit(), -1);
	else
		return (0);
}

int	error_exit(void)
{
	write(2, "ERROR\n", 6);
	return (exit(EXIT_FAILURE), -1);
}
