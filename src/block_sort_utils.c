/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/30 21:07:21 by joamiran         ###   ########.fr       */
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
        printf("index: %d \n", temp->index);
        printf("partition: %d \n", temp->partition);
        temp = temp->next;
    }
    printf("\n");
}

void merge_back_to_a(t_stack **a, t_stack **b)
{
    while ((*b)->size > 0)
        push_a(a, b);
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

