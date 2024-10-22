/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 20:06:27 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void n_partitions(t_stack *stack)
{
    int n_partitions;
    int size;

    size = stack->size;
    n_partitions = size / stack->partition_size;
    if (size % stack->partition_size != 0)
        n_partitions++;
    stack->partitions = n_partitions;
}

// function make partition
void make_partition(t_stack **stack_a, t_stack **stack_b, int partition)
{
    int block_size;
    int elements_in_partition;
    
    block_size = (*stack_a)->partition_size;
    elements_in_partition = 0;
    
    // if the last partition is smaller than the block size
    // we will only process the elements in the last partition
    // and not the full block size
    // this is to ensure we don't process more elements than we have
    if (partition == (*stack_a)->partitions - 1)
        block_size = (*stack_a)->size % block_size;

    while (elements_in_partition < block_size && (*stack_a)->size > 0) // Ensure we only process partition-sized elements
    {
        // Check if the current head belongs to the partition
        if (is_in_partition(*stack_a, (*stack_a)->head, partition))
        {
            push_b(stack_a, stack_b);  // Push to stack_b
            elements_in_partition++;   // Increment the count for elements moved to stack_b
            print_stack(*stack_a, "Stack A");
            print_stack(*stack_b, "Stack B");
        }
        else
        {
            rotate_a(stack_a);  // Rotate stack_a
            print_stack(*stack_a, "Stack A");
        }
    }

    // Print the partition after moving elements
    print_stack(*stack_b, "final partition");
}


// function to sort the partition in stack B and merge it back to stack A
void sort_partition(t_stack **b)
{
   small_sort_block(b); 
}

// function to apply the block sort algorithm to the stack
// divide the stack into partitions and sort each partition
// then merge them back to stack A

void block_sort(t_stack **a, t_stack **b)
{
    int i;

    block_sizer(a);
    n_partitions(*a);
    i = 0;
    while (i < (*a)->partitions)
    {
        make_partition(a, b, i);
        sort_partition(b);
        merge_back_to_a(a, b);
        i++;
    }
}
