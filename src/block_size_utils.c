/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_size_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:49:17 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/05 21:19:58 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to calculate the partition size

static int threshold(int size)
{
    int block_size;

    if (size <= SMALL_SIZE_THRESHOLD)
        return (16);
    else if (size <= MEDIUM_SIZE_THRESHOLD)
        return (size / 20);
    else if (size <= LARGE_SIZE_THRESHOLD)
        return (size / 50);
    else
    {
        block_size = size / 70;
        if (block_size < MIN_BLOCK_SIZE)
            block_size = MIN_BLOCK_SIZE;
        if (block_size > MAX_BLOCK_SIZE)
            block_size = MAX_BLOCK_SIZE;
        return (block_size);
    }
}

void block_sizer(t_stack **stack)
{
    int block_size;

    block_size = threshold((*stack)->size);
    (*stack)->partition_size = block_size;
}
