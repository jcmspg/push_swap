/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/24 17:06:24 by joamiran         ###   ########.fr       */
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

// function check node, and if it is in the partition, push it to stack B
void push_partition(t_stack **a, t_stack **b, int block)
{
    int i;
    int size;

    size = (*a)->size;
    i = 0;
    while (i < size)
    {
        if ((*a)->head->partition == block)
        {
            push_b(a, b);
            printf("Pushing %d to stack B, correscpondint to partition %d\n", (*b)->head->value, block);
        }
        else
            rotate_a(a);
        i++;
    }
}

void move_partitions(t_stack **a, t_stack **b)
{
    int current;
    int total;

    current = 0;
    total = (*a)->partitions;
    
    while (current <= total)
    {
        push_partition(a, b, current);
        current++;
    }
    //print the stack
    print_stack(*a, "Stack A");
}
