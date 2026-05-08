/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffin <eruffin@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:32 by eruffin           #+#    #+#             */
/*   Updated: 2026/05/08 16:29:34 by eruffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdlib.h>
#include <stdio.h>

void printer(int *a, int *b, int n, int size);
int  ascending(const void *a, const void *b);
int  descending(const void *a, const void *b);

int  test_quicksort(void);
int  test_stack(void);

#endif
