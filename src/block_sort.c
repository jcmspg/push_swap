/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/16 21:57:01 by joamiran         ###   ########.fr       */
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

/*void sort_partition(t_stack **stack)
{
    int size;
    t_node *largest;
    t_node *current;

    size = (*stack)->size;
    if (size <= 1)
        return;
    while (size > 0)
    {
        largest = (*stack)->head;
        current = (*stack)->head->next;
        while (current)
        {
            if (current->value > largest->value)
                largest = current;
            current = current->next;
        }
        while ((*stack)->head != largest)
        {
            if (find_position((*stack), largest) <= size / 2)
                rotate_b(stack);
            else
                reverse_rotate_b(stack);
        }
         size--;
    }
}*/

void merge_back_to_a(t_stack **a, t_stack **b)
{
    while ((*b)->size > 0)
    {
        push_a(a, b);
    }
}


void block_sort(t_stack **a, t_stack **b)
{
    partition_and_sort(a, b);
    merge_back_to_a(a, b);
}
