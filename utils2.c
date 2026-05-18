/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:19:49 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/18 14:00:50 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_overflow(long sum, int sign, char *nptr, int len)
{
	if (len > 10 + (sign < 0))
		return (error_exit(), 1);
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

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]))
			error_exit();
		i++;
	}
	return (i);
}
