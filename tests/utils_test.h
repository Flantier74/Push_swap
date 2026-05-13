/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cribstei <cribstei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:32 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/11 13:36:31 by cribstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TEST_H
# define UTILS_TEST_H

# include <stdio.h>
# include <stdlib.h>

# include "../push_swap.h"

void	printer(t_data *data);
int		ascending(const int *a, const int *b);
int		descending(const int *a, const int *b);

t_stack	*init_stack(int a, int b, int c, int d, int e, int f);

int		test_calc_disorder(void);
int		test_insertion_sort_adaptation(void);
int		test_insertion_sort_adaptation_AI(void);
int		test_chunk_based_sorting(void);
int		test_quicksort(void);
int		test_stack_A(void);
int		test_stack_B(void);
int		test_init_rank(void);
int		test_radix_sort(void);

#endif
