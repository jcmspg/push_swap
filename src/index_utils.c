/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/21 20:53:25 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Function to assign index to each node in the stack
void    assign_index(t_stack *stack)
{
    t_node  *tmp;
    t_node  *smallest;
    int     index;
    int     min_value;
    
    index = 0;
    while (index < stack->size)
    {
        tmp = stack->head;
        smallest = stack->head;
        min_value = stack->head->value;
        while (tmp)
        {
            if (tmp->index == -1 && tmp->value < min_value)
            {
                min_value = tmp->value;
                smallest = tmp;
            }
            tmp = tmp->next;
        }
        if (smallest != NULL)
        {
            smallest->index = index;
            index++;
        }
    }
}

// function to determine if the index is in the given partition
int is_in_partition(t_node *node, int partition, int block_size)
{
    t_node *current;
    int index_range;
    
    index_range = block_size * partition; 
    current = node;
    if (current->index >= index_range - block_size && current->index < index_range)
        return (1);
    return (0);
}

