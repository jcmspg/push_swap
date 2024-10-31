/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:42:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/31 22:14:39 by joamiran         ###   ########.fr       */
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

int dist_from_push(t_stack **a, int partition, int index)
{
    t_node *tmp;
    int target;
    int position;
    int distance_from_top;
    int distance_from_bottom;

    tmp = (*a)->head;
    target = -1;
    position = 0;

    while (tmp)
    {
        if (tmp->partition == partition && tmp->index == index)
        {
            target = position;
            break;
        }
        position++;
        tmp = tmp->next;
    }
    if (target == -1)
        return -1;
    distance_from_top = target;
    distance_from_bottom = (*a)->size - target - 1;
    if (distance_from_top <= distance_from_bottom)
        return distance_from_top;
    else
        return -distance_from_bottom;
}

int find_closest_node(t_stack **a, int partition)
{
    t_node *tmp;
    int min_distance;
    int closest_index;
    int current_distance;

    tmp = (*a)->head;
    min_distance = INT_MAX;
    closest_index = -1;

    while (tmp)
    {
        if (tmp->partition == partition)
        {
            current_distance = dist_from_push(a, partition, tmp->index);
            if (ft_abs(current_distance) < ft_abs(min_distance))
            {
                min_distance = current_distance;
                closest_index = tmp->index;
            }
        }
        tmp = tmp->next;
    }
    return (closest_index);
}

