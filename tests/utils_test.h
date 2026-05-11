/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:32 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/08 16:29:34 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TEST_H
#define UTILS_TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "../push_swap.h"

void     printer(t_data *data);
int      ascending(const int *a, const int *b);
int      descending(const int *a, const int *b);

t_stack *init_stack(int a, int b, int c, int d, int e, int f);

int      test_calc_disorder(void);
int      test_insertion_sort_adaptation(void);
int      test_quicksort(void);
int      test_stack_A(void);
int      test_stack_B(void);
int      test_init_rank(void);

#endif
