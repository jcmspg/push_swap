/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/28 19:55:09 by joamiran         ###   ########.fr       */
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

// function check node, and if it is in the partition, push it to stack B
// handle the case when the last partition is only 1 element
void push_partition(t_stack **a, t_stack **b, int block)
{
    int i;
    int size;
    
    size = (*a)->size;
    i = 0;
    while (i < size)
    {
        if ((*a)->head->partition == block)
            push_b(a, b);
        else
            rotate_a(a);
        i++;
        size = (*a)->size;
    }
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
