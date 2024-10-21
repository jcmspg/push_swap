/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/21 20:40:37 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *stack, char *stack_name)
{
    t_node *temp = stack->head;

    printf("Current state of %s:\n", stack_name);
    while (temp)
    {
        printf("%d ", temp->value);  // Print the value of each node
        temp = temp->next;           // Move to the next node
    }
    printf("\n");  // Print a newline at the end for clarity
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

// Helper function to bring the minimum node to the top of the stack
void move_min_to_top(t_stack **stack_b, t_node *min_node)
{
    int index = 0;
    t_node *temp = (*stack_b)->head;

    while (temp && temp != min_node)
    {
        index++;
        temp = temp->next;
    }
    if (index <= (*stack_b)->size / 2)
    {
        while (index-- > 0)
            rotate_b(stack_b);
    }
    else
    {
        index = (*stack_b)->size - index;
        while (index-- > 0)
            reverse_rotate_b(stack_b);
    }
}

void sort_b(t_stack **stack_b)
{
    t_node *min_node;
    t_node *current;
    int stack_size;
    int i;
    int j;

    stack_size = (*stack_b)->size;
    min_node = NULL;
    i = 0;
    while (i < stack_size)
    {
        min_node = find_min_node(*stack_b);
        current = (*stack_b)->head;
        j = 0;
        while (j < stack_size - i)
        {
            if (current->value < min_node->value)
                min_node = current;
            current = current->next;
            j++;
        }
        move_min_to_top(stack_b, min_node);
        i++;
    }
}

    
