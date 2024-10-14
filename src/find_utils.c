/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:58 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/14 19:34:58 by joamiran         ###   ########.fr       */
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
