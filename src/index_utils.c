/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:07:25 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/16 21:24:52 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_indexed(t_stack *stack)
{
    t_node *temp;

    temp = stack->head;
    while (temp)
    {
        if (!temp->index)
            return (0);
        temp = temp->next;
    }
    return (1);
}

void index_stack(t_stack *stack)
{
    t_node *temp;
    int index;
    int smallest;

    
    index = 1;
    while (!is_indexed(stack))
    {
        smallest = find_nth_smallest(stack);
        temp = stack->head;
        while (temp)
        {
            if (temp->value == smallest && !temp->index)
            {
                temp->index = index;
                index++;
                break;
            }
            temp = temp->next;
        }
    }
}
