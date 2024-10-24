/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/24 20:58:24 by joamiran         ###   ########.fr       */
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
    while ((*b)->head)
    {
        push_a(a, b);
        rotate_a(a);
    }
    print_stack(*a, "Stack B");
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

void move_min_to_top(t_stack **stack)
{
    int index;
    t_node *temp;
    t_node *min_node;

    min_node = find_min_node(*stack);
    index = 0;
    temp = (*stack)->head;
    while (temp != min_node)
    {
        temp = temp->next;
        index++;
    }
    if (index < (*stack)->size - index)
    {
        while ((*stack)->head != min_node)
            rotate_b(stack);
    }
    else
    {
        while ((*stack)->head != min_node)
            reverse_rotate_b(stack);
    }
}
