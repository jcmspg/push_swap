/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_size_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:49:17 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/23 20:08:12 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to calculate the partition size

static int threshold(int size)
{
    int block_size;

    if (size <= SMALL_SIZE_THRESHOLD)
        return (3);
    else if (size <= MEDIUM_SIZE_THRESHOLD)
        return (size / 12);
    else if (size <= LARGE_SIZE_THRESHOLD)
        return (size / 20);
    else
    {
        block_size = size / 50;
        if (block_size < 20)
            block_size = 20;
        return (block_size);
    }
}

void block_sizer(t_stack **stack)
{
    int block_size;
    double mean;
    double std_dev;
    double deviation;
    double adjustment;

    deviation = 0;
    mean = ft_mean((*stack)->array, (*stack)->size);
    std_dev = ft_std_dev((*stack)->array, (*stack)->size);
    block_size = threshold((*stack)->size);
    if (mean > 0)
    {
        deviation = std_dev / mean;
        if (deviation > 0.25)
        {
            adjustment = block_size * deviation;
            if (adjustment > block_size * 0.5)
                adjustment = block_size * 0.5;
            block_size += (int)adjustment;
        }
    }
    if (block_size > (*stack)->size)
        block_size = (*stack)->size;
    (*stack)->partition_size = block_size;
}
