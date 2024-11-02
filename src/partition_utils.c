/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/01 22:51:33 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int n_partitions(t_stack *stack)
{
    int n_partitions;
    int size;

    size = stack->size;
    n_partitions = size / stack->partition_size;
    if (size % stack->partition_size != 0)
        n_partitions++;
    return (n_partitions);
}


int count_size(int block, t_stack **stack)
{
    t_node *current;
    int size;
    
    size = 0;
    current = (*stack)->head;
    while (current != NULL)
    {
        if (current->partition == block)
            size++; // Count elements in the specified partition
        current = current->next; // Move to the next node
    }
    return size; // Return the total count of the current partition
}

void assign_partition(t_stack **stack)
{
    t_node  *tmp;
    int     partition;
    
    tmp = (*stack)->head;
    while (tmp)
    {
        partition = tmp->index / (*stack)->partition_size;
        tmp->partition = partition +1;
        tmp = tmp->next;
    }
}

// function check node, and if it is in the partition, push it to stack B
// handle the case when the last partition is only 1 element
// it checks all the corresponding indexes of the partition and calculates the distance from the top for each one. then it pushes the one with the smallest distance to the top

void push_partition(t_stack **a, t_stack **b, int block)
{
    int i;
    int size;
    int closest_index;
    int distance;

    size = count_size(block, a);
    i = 0;
    while (i < size)
    {
        closest_index = find_closest_node(a, block);
        distance = dist_from_push(a, block, closest_index);

        while ((*a)->head->index != closest_index)
        {
            if (distance > 0)
            {
                rotate_a(a);
                distance--;
            }
            else
            {
                reverse_rotate_a(a);
                distance++;
            }
        }
        push_b(a, b);
        i++;
    }
}



//static int find_extreme_node_in_block(t_stack **a, int block, int mode) {
//    t_node *current = (*a)->head;
//    int extreme_index = -1;
//
//    // Loop through all elements in the partition block
//    while (current != NULL) {
//        if (current->partition == block) {
//            if (extreme_index == -1 || 
//               (mode == 1 && current->index < extreme_index) || 
//               (mode == -1 && current->index > extreme_index)) {
//                extreme_index = current->index;
//            }
//        }
//        current = current->next;
//    }
//    return extreme_index;
//}

//void push_partition_ordered(t_stack **a, t_stack **b, int block) {
//    int i;
//    int size;
//    int target_index;
//    int distance;
//
//    size = count_size(block, a); // Count how many nodes are in the current partition
//    i = 0;
//
//    while (i < size) {
//        // Find the smallest or largest index in the partition block
//        target_index = find_extreme_node_in_block(a, block, 1); // Pass 1 for smallest, -1 for largest
//        distance = dist_from_push(a, block, target_index);
//
//        // Bring the closest extreme element (smallest or largest) to the top of A
//        while ((*a)->head->index != target_index) {
//            if (distance > 0) {
//                rotate_a(a);
//                distance--;
//            } else {
//                reverse_rotate_a(a);
//                distance++;
//            }
//        }
//        
//        // Push the smallest or largest element to B
//        push_b(a, b);
//        i++;
//    }
//}


