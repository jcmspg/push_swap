/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:06:33 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/04 20:43:46 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
	t_node *temp;

	if ((*stack)->size < 2)
		return;
	temp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	(*stack)->head->prev = NULL;
	temp->next = (*stack)->head->next;
	(*stack)->head->next = temp;
	temp->prev = (*stack)->head;
	if (temp->next)
		temp->next->prev = temp;
	if ((*stack)->tail == (*stack)->head)
		(*stack)->tail = temp;
}

void push(t_stack **stack1, t_stack **stack2)
{
	t_node *temp;

	if (!(*stack1)->size)
		return;
	temp = (*stack1)->head;
	(*stack1)->head = (*stack1)->head->next;
	if ((*stack1)->head)
		(*stack1)->head->prev = NULL;
	temp->next = (*stack2)->head;
	if ((*stack2)->head)
		(*stack2)->head->prev = temp;
	(*stack2)->head = temp;
	if (!(*stack2)->tail)
		(*stack2)->tail = (*stack2)->head;
	(*stack1)->size--;
	(*stack2)->size++;
}

void rotate(t_stack **stack)
{
	t_node *temp;

	if ((*stack)->size < 2)
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

	if ((*stack)->size < 2)
		return;
	temp = (*stack)->tail;
	(*stack)->tail = (*stack)->tail->prev;
	(*stack)->tail->next = NULL;
	(*stack)->head->prev = temp;
	temp->next = (*stack)->head;
	temp->prev = NULL;
	(*stack)->head = temp;
}
