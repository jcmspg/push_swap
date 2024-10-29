/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:42:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/29 22:34:02 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int optimal_rotation(t_stack *stack, int target_partition)
{
    if (stack == NULL || stack->size == 0 || stack->head == NULL)
        return 0;
    
    t_node *tmp;
    int target;
    int position;
    int distance_from_top;
    int distance_from_bottom;

    tmp = stack->head;
    target = -1;
    position = 0;

    while (tmp)
    {
        if (tmp->partition == target_partition)
        {
            target = position;
            break;
        }
        position++;
        tmp = tmp->next;
    }
    if (target == -1)
        return 0;

    distance_from_top = target;
    distance_from_bottom = stack->size - target;
    if (distance_from_top <= distance_from_bottom)
        return distance_from_top;
    else
        return -distance_from_bottom;
}

