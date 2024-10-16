/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/16 21:57:01 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_partition(t_stack **stack)
{
    int size;
    t_node *smallest;
    t_node *current;

    size = (*stack)->size;
    if (size <= 1)
        return;
    while (size > 0)
    {
        smallest = (*stack)->head;
        current = (*stack)->head->next;
        while (current)
        {
            if (current->value < smallest->value)
                smallest = current;
            current = current->next;
        }
        while ((*stack)->head != smallest)
        {
            if (smallest->index <= size / 2)
                rotate_b(stack);
            else
                reverse_rotate_b(stack);
        }
        size--;
    }
}



static void merge_back_to_a(t_stack **a, t_stack **b)
{
    while ((*b)->size > 0)
    {
        push_a(a, b);
    }
}


void block_sort(t_stack **a, t_stack **b)
{
    partition_stack(a, b);
    merge_back_to_a(a, b);
}
