/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/06 21:38:10 by joamiran         ###   ########.fr       */
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

//
//void push_partition(t_stack **a, t_stack **b)
//{
//    if ((*a)->head == NULL)
//        return ;
//
//    int size = (*a)->size;
//    while ((*a)->size > 2)
//    {
//        if ((*a)->head->index == size || (*a)->head->index == size - 1)
//            rotate_a(a);
//        else
//        {
//            if ((*a)->head->index > size / 2)
//            {                
//                push_b(a, b);
//                rotate_b(b);
//            }
//            else
//                push_b(a, b);
//        }
//    }
//}
//



//static int find_dist_to_index(t_stack **a, int block, int target_index)
//{
//    t_node *tmp;
//    int target;
//    int position;
//    int distance_from_top;
//    int distance_from_bottom;
//
//    tmp = (*a)->head;
//    target = -1;
//    position = 0;
//
//    while (tmp)
//    {
//        if (tmp->partition == block && tmp->index == target_index)
//        {
//            target = position;
//            break;
//        }
//        position++;
//        tmp = tmp->next;
//    }
//    if (target == -1)
//        return -1;
//
//    distance_from_top = target;
//    distance_from_bottom = (*a)->size - target - 1;
//
//    if (distance_from_top <= distance_from_bottom)
//        return distance_from_top;
//    else
//        return -distance_from_bottom;
//}
//

