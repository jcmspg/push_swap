/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/21 21:34:01 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int block_sizer(t_stack **stack)
{
    int size = (*stack)->size;
    if (size <= 0)
        return 0;

    int range = find_max(*stack) - find_min(*stack);
    int block_size = 1;
    if (size <= SMALL_SIZE_THRESHOLD)
    {
        block_size = size / BLOCK_SIZE_DIVISOR_SMALL;
        if (block_size < 3)
            block_size = 3;
    }
    else if (size <= MEDIUM_SIZE_THRESHOLD)
    {
        block_size = size / BLOCK_SIZE_DIVISOR_MEDIUM;
        if (block_size < 5)
            block_size = 5;
    }
    else
    {
        if (range > LARGE_RANGE_THRESHOLD_1)
            block_size = size / BLOCK_SIZE_DIVISOR_LARGE_1;
        else if (range > LARGE_RANGE_THRESHOLD_2)
            block_size = size / BLOCK_SIZE_DIVISOR_LARGE_2;
        else if (range > LARGE_RANGE_THRESHOLD_3)
            block_size = size / BLOCK_SIZE_DIVISOR_LARGE_3;
        else
            block_size = size / BLOCK_SIZE_DIVISOR_LARGE_4;
    }
    if (block_size > 5)
        block_size = 5;
    else if (block_size < 1)
        block_size = 1;
    return block_size;
}


// Function to partition stack a into a block and send it to stack b
void partition_stack(t_stack **stack_a, t_stack **stack_b, int partition)
{
    int pushed;
    int block_size;
    int count;
    t_node *current;

    pushed = 0;
    block_size = block_sizer(stack_a);
    while ((*stack_b)->size < block_size && (*stack_a)->size > 0)
    {
        current = (*stack_a)->head;
        count = 0;
        while (pushed < block_size && count++ < (*stack_a)->size)
        {
            if (is_in_partition(current, partition, block_size))
            {
                push_b(stack_a, stack_b);
                pushed++;
            }
            else
                rotate_a(stack_a);
            if ((*stack_a)->head == NULL)
                break;
            current = (*stack_a)->head;
        }
        if (pushed < block_size)
            break;
    }
}

// Function to sort the partitioned block in stack b and push it back to stack a
void partition_sort(t_stack **stack_a, t_stack **stack_b)
{
    if ((*stack_b)->size <= 5)
        sort_b(stack_b);
    merge_back_to_a(stack_a, stack_b);
}

void partition_and_sort(t_stack **stack_a, t_stack **stack_b)
{
    int partition_max;
    int partition;
    int i;

    i = 0;
    assign_index(*stack_a);
    //print index
    while (i++ < (*stack_a)->size)
    {
        printf("index: %d\n", (*stack_a)->head->index);
    }
    partition = 0;
    partition_max = (*stack_a)->size / block_sizer(stack_a);

    while (partition < partition_max)
    {
        partition_stack(stack_a, stack_b, partition);
        partition_sort(stack_a, stack_b);
        partition++;
    }
    printf("Partitioned and sorted\n");
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");
}


