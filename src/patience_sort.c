/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:46:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/02 00:18:07 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// function to push from b to a, while keeping the stack sorted based on index
// when pushing from b to a, we must compare the index of the top of the stack a with the index of the top of the stack b and then place the smallest on top of the stack a, while keeping the stack sorted. for that we must ideally only perform swaps, sometimes rotations, but when rotated, we need to reverte back to the sorted state.
//



//static int find_pos(t_stack **a, int value) {
//    int pos = 0;
//    t_node *current = (*a)->head;
//
//    // Find the position where the new value should be inserted
//    pos = current->index;    
//    // If value is larger than all, return size (to insert at bottom)
//    if (value > current->index) {
//        return (*a)->size;
//    }
//    return pos;
//}



//void push_back_sort(t_stack **a, t_stack **b) {
//    while ((*b)->size > 0) {
//        int value_to_insert = (*b)->head->index;
//        
//        // Determine where to insert the element
//        int insert_pos = value_to_insert;
//        int size_a = (*a)->size;
//
//        // If stack A is empty, just push the value
//        if (size_a == 0) {
//            push_a(a, b);
//        } else {
//            // Rotate to the correct position for insertion
//            if (insert_pos == size_a) {
//                // If inserting at the bottom, just push it
//                push_a(a, b);
//            } else {
//                // Calculate rotations to bring the insert position to the top
//                int rotations = insert_pos; // Positions from top
//                int reverse_rotations = size_a - insert_pos; // Positions from bottom
//
//                // Rotate to the right position
//                if (rotations <= reverse_rotations) {
//                    for (int i = 0; i < rotations; i++) {
//                        rotate_a(a); // Rotate A to position the insert point
//                    }
//                } else {
//                    for (int i = 0; i < reverse_rotations; i++) {
//                        reverse_rotate_a(a); // Rotate A to position the insert point from the bottom
//                    }
//                }
//
//                // Push the element from B to A
//                push_a(a, b);
//            }
//        }
//    }
//}

void push_back_sort(t_stack **a, t_stack **b) {
    int rotations;
    int reverse_rotations;
    int value_to_insert;
    int insert_pos;
    int size_a;
    
    while ((*b)->size > 0) {
        value_to_insert = (*b)->head->index;
        size_a = (*a)->size;

        if (size_a == 0) {
            push_a(a, b); // Push to an empty stack
        } else {
            // Find the correct position to insert into A
            insert_pos = (*b)->head->index;
            rotations = insert_pos;
            reverse_rotations = size_a - insert_pos;

            // Rotate in the direction of the minimum moves
            if (rotations <= reverse_rotations) {
                for (int i = 0; i < rotations; i++) {
                    rotate_a(a);
                }
            } else {
                for (int i = 0; i < reverse_rotations; i++) {
                    reverse_rotate_a(a);
                }
            }

            // Now push from B to A
            push_a(a, b);
        }
    }
}

// function tthat takes b head and places it in the correct position in a

//push a partition from b to a from smallest to biggest


void lazy_sort(t_stack **a, t_stack **b) {
    int i = (*a)->partitions;
    while (i > 0)
    {
        push_back_sort(a, b);
        i--;
    }
}


