/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:06:33 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 18:57:44 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    t_node *first, *second;

    if ((*stack)->size < 2 || !(*stack)->head->next)
        return; // Nothing to swap

    first = (*stack)->head;  // Get the first node
    second = first->next;    // Get the second node

    // Swap the nodes
    first->next = second->next; // first's next points to the node after second
    if (first->next)            // if there's a node after second
        first->next->prev = first; // update its prev to first

    second->prev = NULL;       // second becomes the new head
    second->next = first;      // second's next points to first
    first->prev = second;      // first's prev points to second

    (*stack)->head = second;   // Update head of the stack

    // Update tail if needed
    if ((*stack)->tail == first)
        (*stack)->tail = first; // tail remains the same if it was the first element
}

void push(t_stack **stack1, t_stack **stack2)
{
    t_node *temp;

    if (!(*stack1)->size || !(*stack1)->head)
        return;  // No elements to push

    temp = (*stack1)->head;           // Get the node to push
    (*stack1)->head = (*stack1)->head->next; // Move head of stack1
    if ((*stack1)->head)
        (*stack1)->head->prev = NULL; // Update new head's prev

    // Prepare to push to stack2
    temp->next = (*stack2)->head;     // Link new node to top of stack2
    if ((*stack2)->head) 
        (*stack2)->head->prev = temp; // Update previous top of stack2
    (*stack2)->head = temp;           // Update head of stack2
    temp->prev = NULL;                // New top of stack2 has no prev

    if (!(*stack2)->tail)              // If stack2 was empty, update tail
        (*stack2)->tail = temp;

    (*stack1)->size--;                // Update sizes
    (*stack2)->size++;
}

void rotate(t_stack **stack)
{
	t_node *temp;

	if ((*stack)->size < 2 || !(*stack)->head->next || !(*stack)->head)
		return;
	temp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	(*stack)->head->prev = NULL;
	(*stack)->tail->next = temp;
	temp->prev = (*stack)->tail;
	temp->next = NULL;
	(*stack)->tail = temp;
}

void reverse_rotate(t_stack **stack)
{
	t_node *temp;

	if ((*stack)->size < 2 || !(*stack)->head->next || !(*stack)->head)
		return;
	temp = (*stack)->tail;
	(*stack)->tail = (*stack)->tail->prev;
	(*stack)->tail->next = NULL;
	(*stack)->head->prev = temp;
	temp->next = (*stack)->head;
	temp->prev = NULL;
	(*stack)->head = temp;
}

