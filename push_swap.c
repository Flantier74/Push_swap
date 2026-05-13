/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:23:06 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/09 16:23:09 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int select_strategy(char **argv)
{
	if (!ft_strcmp("--simple", argv[1]))
		return (1);
	else if (!ft_strcmp("--medium", argv[1]))
		return (2);
	else if (!ft_strcmp("--complex", argv[1]))
		return (3);
	else if (!ft_strcmp("--adaptative", argv[1]))
		return (0);
	return (-1);
}

int main(int argc, char *argv[])
{
	int i;
	int strat;

	i = 1;
	strat = select_strategy(argv);
	if (strat >= 0)
		i++;
	while (i < argc)
	{

		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
