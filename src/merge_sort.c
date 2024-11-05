/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:07:12 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/05 20:13:53 by joamiran         ###   ########.fr       */
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
