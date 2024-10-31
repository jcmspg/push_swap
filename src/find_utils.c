/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:58 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/31 20:47:25 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// find the minimum value in the stack
int find_min(t_stack *stack)
{
    t_node *temp;
    int min;

    temp = stack->head;
    min = INT_MAX;
    while (temp)
    {
        if (temp->value < min)
            min = temp->value;
        temp = temp->next;
    }
    return (min);
}

// find the maximum value in the stack
int find_max(t_stack *stack)
{
    t_node *temp;
    int max;

    temp = stack->head;
    max = INT_MIN;
    while (temp)
    {
        if (temp->value > max)
            max = temp->value;
        temp = temp->next;
    }
    return (max);
}

// find the second minimum value in the stack
int find_second_min(t_stack *stack)
{
    t_node *temp;
    int min;
    int second_min;

    temp = stack->head;
    min = INT_MAX;
    second_min = INT_MAX;
    while (temp)
    {
        if (temp->value < min)
        {
            second_min = min;
            min = temp->value;
        }
        else if (temp->value < second_min && temp->value != min)
            second_min = temp->value;
        temp = temp->next;
    }
    return (second_min);
}

int find_second_max(t_stack *stack)
{
    t_node *temp;
    int max;
    int second_max;

    temp = stack->head;
    max = INT_MIN;
    second_max = INT_MIN;
    while (temp)
    {
        if (temp->value > max)
        {
            second_max = max;
            max = temp->value;
        }
        else if (temp->value > second_max && temp->value != max)
            second_max = temp->value;
        temp = temp->next;
    }
    return (second_max);
}


int find_nth_smallest(t_stack *stack)
{
    t_node *current;
    int nth_smol;

    current = stack->head;
    nth_smol = INT_MAX;
    while(current)
    {
        if (current->value < nth_smol && !current->index)
                nth_smol = current->value;
        current = current->next;
    }
    return (nth_smol);
}

int find_partition_biggest(t_stack *stack, int partition)
{
    t_node *current;
    int nth_big;
    int i;

    current = stack->head;
    nth_big = INT_MIN;
    i = 0;
    while(current)
    {
        if (current->value > nth_big && current->partition == partition)
                nth_big = current->value;
        current = current->next;
    }
    return (nth_big);
}

int find_position(t_stack *stack, t_node *node)
{
    t_node *current;
    int position;

    current = stack->head;
    position = 0;
    while (current)
    {
        if (current == node)
            return (position);
        current = current->next;
        position++;
    }
    return (position);
}
