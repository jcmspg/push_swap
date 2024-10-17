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
    int block_size = 1;
    // Determine block size based on stack size and value range
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
    if (block_size < 1) // Handle edge case where block size is less than 1
        block_size = 1;
    return block_size;
}

// function to determine if the index is in the partitioned block
int is_in_partition(t_stack *stack, int index, int size)
{
    int i = 0;
    t_node *temp = stack->head;

    while (i < size)
    {
        if (temp->index == index)
            return (1);
        temp = temp->next;
        i++;
    }
    return (0);
}

// function to partition stack a into stack b
void partition_stack(t_stack **stack_a, t_stack **stack_b)
{
    int size = block_size(stack_a); // Get the size of the partitioned block
    int elements_pushed = 0; // To track how many elements we've pushed

    printf("Partitioning stack A: Current size: %d, Block size: %d\n", (*stack_a)->size, size);

    // Loop until we have pushed the calculated size or there are no more elements
    while (elements_pushed < size && (*stack_a)->size > 0)
    {
        // Print the current top value of stack A before each operation
        printf("Current top of stack A: %d\n", (*stack_a)->head->value);

        // check if the value corresponds to the partitioned block
        if (is_in_partition(*stack_a, (*stack_a)->head->index, size))
        {
            push_b(stack_a, stack_b);
            elements_pushed++; // Increment the number of pushed elements
            printf("Pushed to stack B, current stack B: ");
            print_stack(*stack_b, "stack b"); // Custom function to print stack B
        }
        else
        {
            rotate_a(stack_a);
            printf("Rotated stack A, current stack A: ");
            print_stack(*stack_a, "stack a"); // Custom function to print stack A
        }
    }
}

// Function to find and push the largest element from stack B to stack A
void partition_sort(t_stack **stack_a, t_stack **stack_b) {
    while ((*stack_b)->size > 0) {
        // Find the largest element
        t_node *largest = (*stack_b)->head;
        t_node *current = largest->next;

        // Loop to find the largest node in stack B
        while (current) {
            if (current->value > largest->value) {
                largest = current; // Update the largest node
            }
            current = current->next;
        }

        // Get the position of the largest node
        int pos = find_position(*stack_b, largest); // Position of largest element

        // Rotate stack B until the largest element is at the top
        if (pos <= (*stack_b)->size / 2) {
            while ((*stack_b)->head != largest) {
                rotate_b(stack_b); // Rotate to bring the largest to the top
            }
        } else {
            while ((*stack_b)->head != largest) {
                reverse_rotate_b(stack_b); // Reverse rotate to bring it to the top
            }
        }

        // Now push the largest element to stack A
        push_a(stack_a, stack_b);
        printf("Pushed largest %d to stack A, current state of stack A: ", largest->value);
        print_stack(*stack_a, "stack A"); // Debug print to show current state
    }
}








void partition_and_sort(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_a)->size > 0)
    {
        // partition stack a into stack b
        partition_stack(stack_a, stack_b);
        printf("Partitioned stack A, current state of stack s:\n ");
        print_stack(*stack_a, "stack a\n");
        print_stack(*stack_b, "stack b\n");
        // sort the partitioned block in stack b
        partition_sort(stack_b, stack_a);
    }
}
