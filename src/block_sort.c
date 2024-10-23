/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/23 19:46:04 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void selection_sort(t_stack **a, t_stack **b)
{
    int i;
    int min;
    int max;

    i = 0;
    min = (*a)->min;
    max = (*a)->max;
    while (i < (*a)->partition_size)
    {
        if ((*a)->head->value == min || (*a)->head->value == max)
            push_b(a, b);
        else
            rotate_a(a);
        i++;
    }
    while ((*b)->size > 0)
        push_a(a, b);
}


void sort_p(t_stack **a, t_stack **b)
{
    if ((*a)->partition_size > 5 && (*a)->partition_size <= 20)
        selection_sort(a, b);
    else if ((*a)->partition_size > 20)
        merge_sort_partition(a, b, (*a)->partition_size);
}



void sort_partition(t_stack **a, t_stack **b)
{
    if ((*b)->size == 1)
        return;
    else if ((*b)->size <= 5)
        small_sort_block(b);
    else
        sort_p(a, b);
}

void block_sort(t_stack **a, t_stack **b)
{
    int i;

    assign_index(*a);
    set_array(a);
    block_sizer(a);
    n_partitions(*a);
    assign_partition(a);
    i = 1;
    while (i < (*a)->partitions)
    {
        push_partition(a, b, i);
        sort_partition(a, b);
        i++;
    }
}
