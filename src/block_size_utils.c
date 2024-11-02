/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_size_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:49:17 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/01 22:45:57 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to calculate the partition size

static int threshold(int size)
{
    int block_size;

    if (size <= SMALL_SIZE_THRESHOLD)
        return (15);
    else if (size <= MEDIUM_SIZE_THRESHOLD)
        return (size / 20);
    else if (size <= LARGE_SIZE_THRESHOLD)
        return (size / 50);
    else
    {
        block_size = size / 70;
        if (block_size < 30)
            block_size = 30;
        return (block_size);
    }
}

void block_sizer(t_stack **stack)
{
    int block_size;

    block_size = threshold((*stack)->size);
    (*stack)->partition_size = block_size;
}
