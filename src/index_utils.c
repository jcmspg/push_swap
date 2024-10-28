/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/28 20:28:57 by joamiran         ###   ########.fr       */
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
        smallest = NULL;
        min_value = INT_MAX;
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

// function to print all the nodes and their indexes
void   print_index(t_stack *stack)
{
    t_node  *tmp;

    tmp = stack->head;
    while (tmp)
    {
        printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
}

void print_partition(t_stack *stack)
{
    t_node  *tmp;

    tmp = stack->head;
    while (tmp)
    {
        printf("Value: %d, Partition: %d\n", tmp->value, tmp->partition);
        tmp = tmp->next;
    }
}
