/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/23 20:07:08 by joamiran         ###   ########.fr       */
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


    i = 0;
    while (i <= (*a)->partition_size)
    {
        if ((*a)->head->partition == block)
            push_b(a, b);
        else
            rotate_a(a);
        i++;
    }
}



