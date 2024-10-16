/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/16 22:09:12 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int block_size(t_stack **stack)
{
    int size = (*stack)->size; // Get the size of the stack
    if (size <= 0) // Handle edge case where stack is empty
        return 0;

    int range = find_max(*stack) - find_min(*stack);

    // Determine block size based on stack size and value range
    if (size <= SMALL_SIZE_THRESHOLD)
        return (size / BLOCK_SIZE_DIVISOR_SMALL);
    else if (size <= MEDIUM_SIZE_THRESHOLD)
        return (size / BLOCK_SIZE_DIVISOR_MEDIUM);
    else 
    {
        if (range > LARGE_RANGE_THRESHOLD_1)
            return (size / BLOCK_SIZE_DIVISOR_LARGE_1);
        else if (range > LARGE_RANGE_THRESHOLD_2)
            return (size / BLOCK_SIZE_DIVISOR_LARGE_2);
        else if (range > LARGE_RANGE_THRESHOLD_3)
            return (size / BLOCK_SIZE_DIVISOR_LARGE_3);
        else
            return (size / BLOCK_SIZE_DIVISOR_LARGE_4);
    }
}

void partition_stack(t_stack **stack_a, t_stack **stack_b)
{
    int block;
    int size;
    int current_block;
    int i;

    size = (*stack_a)->size;
    block = block_size(stack_a);
    current_block = 1;
    i = 0;

    while (i < size)
    {
        if ((*stack_a)->head->index <= (current_block * block))
        {
            push_b(stack_a, stack_b);
            sort_partition(stack_b);
        }
        else
            rotate_a(stack_a);
        if (i > 0 && i % block == 0)
            current_block++;
        i++;
    }
}
