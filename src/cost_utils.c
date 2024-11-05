/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:58 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/05 20:56:37 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_move_cost(t_stack **a, t_node *node)
{
    int cost = 0;
    t_node *current = (*a)->head;

    // Find the index of the node in stack A
    int index = node->index;
    int distance_from_top = 0;

    // Traverse the stack to calculate the distance to the top of the stack
    while (current != NULL)
    {
        if (current->index == index)
            break;
        current = current->next;
        distance_from_top++;
    }

    // Calculate the cost: the cost is the smaller of rotating or reverse rotating
    int total_size = (*a)->size;

    // Rotation is cheaper when the element is closer to the top
    if (distance_from_top <= total_size / 2)
        cost = distance_from_top;  // Cost of rotating
    else
        cost = total_size - distance_from_top;  // Cost of reverse rotating

    return cost;
}

int calculate_cost_to_move_partition(t_stack **a, int partition_index)
{
    int cost = 0;
    t_node *current = (*a)->head;

    // Calculate the total cost for the specified partition
    while (current != NULL)
    {
        // Check if the current node belongs to the specified partition
        if (current->partition == partition_index)
        {
            // Add the move cost of the current node to the total cost
            cost += calculate_move_cost(a, current);
        }
        current = current->next;
    }

    return cost;
}


