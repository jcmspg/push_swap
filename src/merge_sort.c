/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:07:12 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/07 19:46:34 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_b(t_stack **a, t_stack **b)
{
    int current_index;
    int median_index;

    median_index = (*a)->size / 2;
    while((*a)->size > 1)
    {
        current_index = (*a)->head->index;
        if (current_index == median_index)
            rotate_a(a);
        else
        {
            push_b(a, b);
            if (current_index > median_index)
                rotate_b(b);
        }
    }
}


void push_sorted_to_a(t_stack **a, t_stack **b)
{
    int median_index;
    int current_index;
    
    if ((*a)->size == 0)
        push_a(a, b);
    median_index = (*a)->head->index;
    while ((*b)->size > 0)
    {
        current_index = (*b)->head->index;
        if (current_index == median_index)
        {
            rotate_b(b);
            continue;
        }
        else
        {
            push_a(a, b);
            if (current_index > median_index)
                rotate_a(a);
        }
    }
}

static void push_partition_to_a(t_stack **a, t_stack **b, int partition)
{
    int counter = 0;
    int partition_size;
    
    partition_size = count_size(partition, b);
    // Push elements from B that belong to the current partition to A
    while (partition_size-- > 0)
    {
        if ((*b)->head->partition != partition)
            rotate_b(b);
        else if ((*b)->head->partition == partition)
        {
            if ((*b)->head->index < (*a)->head->index)
                push_a(a, b);
            else
            {
                while ((*b)->head->index > (*a)->head->index)
                {
                    rotate_a(a);
                    counter++;
                }
                push_a(a, b);
                while (counter > 0)
                {
                    reverse_rotate_a(a);
                    counter--;
                }
            }
        }
        partition_size--;
    }
}

void merge_back(t_stack **a, t_stack **b)
{ // Start with the highest partition in B
    int current_partition;

    current_partition = (*a)->partitions -1;
    // Merge partitions back into A in descending order
    while ((*b)->size > 0 || current_partition > 0)
    {
        push_partition_to_a(a, b, current_partition);
        current_partition--;
    }
} 
