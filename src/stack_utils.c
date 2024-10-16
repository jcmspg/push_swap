/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:59 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/16 20:08:32 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack functions

// create a new node
t_node	*new_node(int value)
{
    t_node	*node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

// create a new stack
t_stack	*new_stack()
{
    t_stack	*stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return (stack);
}

// push a new node into the stack
void    node_to_stack(t_stack *stack, int value)
{
    t_node	*node;

    node = new_node(value);
    if (!node)
        return ;
    if (!stack->head)
    {
        stack->head = node;
        stack->tail = node;
    }
    else
    {
        stack->tail->next = node;
        node->prev = stack->tail;
        stack->tail = node;
    }
    stack->size++;
}

// free the nodes and the stack
void	free_stack(t_stack *stack)
{
    t_node	*tmp;

    while (stack->head)
    {
        tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }
    free(stack);
}
