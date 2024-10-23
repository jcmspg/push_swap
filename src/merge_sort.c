/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:07:12 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/23 19:47:02 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void merge_two_sorted_stacks(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b) {
    // This function merges the two sorted halves back into stack B
    while (size_a > 0 || size_b > 0) {
        if (size_a > 0 && size_b > 0) {
            // Compare the top elements of both stacks
            if ((*stack_a)->head->value <= (*stack_b)->head->value) {
                push_b(stack_a,stack_b); // Move from stack A to stack B
                size_a--;
            } else {
                push_a(stack_a, stack_b); // Move from stack B to stack A
                size_b--;
            }
        } else if (size_a > 0) {
            // If stack B is empty, move the remaining elements from stack A to stack B
            push_b(stack_a, stack_b);
            size_a--;
        } else if (size_b > 0) {
            // If stack A is empty, move the remaining elements from stack B to stack A
            push_a(stack_a, stack_b);
            size_b--;
        }
    }
}



void merge_sort_partition(t_stack **stack_a, t_stack **stack_b, int partition_size) {
    // Base case: If partition size is 1 or 0, return as it's already sorted
    if (partition_size <= 1) return;

    int mid = partition_size / 2;

    // Move the first half of the partition to stack A
    for (int i = 0; i < mid; i++) {
        push_a(stack_a, stack_b);
    }

    // Sort the first half (now in stack A)
    merge_sort_partition(stack_a, stack_b, mid);

    // Move the sorted first half back to stack B
    for (int i = 0; i < mid; i++) {
        push_b(stack_a, stack_b);
    }

    // Now sort the second half (remaining elements in stack B)
    // Start sorting the second half :vsplitin stack B
    for (int i = mid; i < partition_size; i++) {
        push_a(stack_a, stack_b);
    }

    // Sort the second half (now in stack A)
    merge_sort_partition(stack_a, stack_b, partition_size - mid);

    // Merge the two halves back into stack B
    merge_two_sorted_stacks(stack_a, stack_b, mid, partition_size - mid);
}


