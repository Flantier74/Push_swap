/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:56:58 by eruffin           #+#    #+#             */
/*   Updated: 2026/04/28 12:11:45 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	sum;
	int	len;

	len = 0;
	sign = 1;
	sum = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(nptr[len]))
		len++;
	while (ft_isdigit(*nptr))
	{
		sum += (*nptr - 48) * ft_power(10, len - 1);
		nptr++;
		len--;
	}
	return (sum * sign);
}

int	ft_power(int nb, int pow)
{
	if (pow == 1)
		return (nb);
	if (pow == 0)
		return (1);
	return (nb *= ft_power(nb, pow - 1));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
