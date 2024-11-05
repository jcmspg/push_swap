/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:06:33 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/05 18:48:59 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swaps the top two nodes of a stack
void swap(t_stack **stack)
{
    t_node *temp;

    if ((*stack)->size < 2 || !(*stack)->head->next || !(*stack)->head)
        return;
    if ((*stack)->head == NULL)
        return;
    if ((!*stack))
        return;

    temp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    
    temp->next = (*stack)->head->next;
    (*stack)->head->next = temp;
}

// pushes the top node of a stack to another stack
void push(t_stack **stack1, t_stack **stack2)
{
    t_node *temp;

    if ((*stack1)->size == 0 || !(*stack1)->head)
        return;
    if ((*stack2)->head == NULL)
    {
        (*stack2)->head = (*stack1)->head;
        (*stack2)->tail = (*stack1)->head;
        (*stack1)->head = (*stack1)->head->next;
        (*stack2)->head->next = NULL;
        (*stack1)->size--;
        (*stack2)->size++;
        return;
    }
    else
    {
        temp = (*stack1)->head;
        (*stack1)->head = (*stack1)->head->next;
        temp->next = (*stack2)->head;
        (*stack2)->head = temp;
        (*stack1)->size--;
        (*stack2)->size++;
    }
}

// rotates the stack by moving the top node to the bottom
void rotate(t_stack **stack)
{
	t_node *temp;

	if ((*stack)->size < 2 || !(*stack)->head->next || !(*stack)->head)
		return;
    if ((*stack)->head == NULL)
        return;
    if ((!*stack))
        return;
    
    temp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    (*stack)->tail->next = temp;
    (*stack)->tail = temp;
    (*stack)->tail->next = NULL;
}

// rotates the stack by moving the bottom node to the top
void reverse_rotate(t_stack **stack)
{
	t_node *temp;
    
    if (!(*stack) || !stack || (*stack)->size < 2)
        return;
    
    temp = (*stack)->head;
    while (temp->next->next)
        temp = temp->next;
    (*stack)->tail->next = (*stack)->head;
    (*stack)->head = (*stack)->tail;
    (*stack)->tail = temp;
    (*stack)->tail->next = NULL;
}

