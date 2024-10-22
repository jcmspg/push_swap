/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 18:53:26 by joamiran         ###   ########.fr       */
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

// function to check if the node is in the partition
int is_in_partition(t_stack *stack, t_node *node, int partition)
{
    int block_size;
    int lower_bound;
    int upper_bound;
    
    if (!node)
        return (0);

    block_size = stack->partition_size;
    lower_bound = partition * block_size;
    upper_bound = (partition + 1) * block_size;

    printf("Node index: %d, Partition %d, Block Size: %d, Lower: %d, Upper: %d\n", 
        node->index, partition, block_size, lower_bound, upper_bound);



    // Check if node's index falls within the range for this partition
    if (node->index >= lower_bound && node->index < upper_bound)
        return (1);
     return (0);
}
    
