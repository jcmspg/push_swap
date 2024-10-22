/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 17:47:51 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *stack, char *stack_name)
{
    t_node *temp = stack->head;

    printf("Current state of %s:\n", stack_name);
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void merge_back_to_a(t_stack **a, t_stack **b)
{
    while ((*b)->size > 0)
    {
        push_a(a, b);
        rotate_a(a);
    }
}

t_node *find_min_node(t_stack *stack)
{
    t_node *temp = stack->head;
    t_node *min_node = temp;

    while (temp)
    {
        if (temp->value < min_node->value)
            min_node = temp;
        temp = temp->next;
    }
    return min_node;
}




