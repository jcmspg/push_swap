/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:46:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/31 23:14:53 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static bool is_sorted_ascending_by_index(t_stack **a)
{
    t_node *tmp = (*a)->head;

    while (tmp && tmp->next)
    {
        if (tmp->index > tmp->next->index)
            return false;
        tmp = tmp->next;
    }

    return true;
}
*/
static int find_last_index(t_stack **a)
{
    if ((*a) == NULL || (*a)->head == NULL)
        return -1;

    t_node *tmp = (*a)->head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return tmp->index;
}

void push_back_sort(t_stack **a, t_stack **b, int partition)
{
    int last_index;
    int a_top;
    int b_top;

    while ((*b) != NULL && (*b)->head != NULL && (*b)->head->partition == partition)
    {
        b_top = (*b)->head->index;
        
        if ((*a) == NULL || (*a)->head == NULL)
        {
            push_a(a, b);
            continue;
        }

        a_top = (*a)->head->index;
        last_index = find_last_index(a);

        if (b_top < a_top)
        {
            while ((*a)->head != NULL && (*a)->head->index > b_top)
            {
                reverse_rotate_a(a);
                if ((*a)->head->index <= b_top)
                    break;
            }
        }
        else if (b_top > last_index)
        {
            while ((*a)->head != NULL && (*a)->head->index != last_index)
            {
                rotate_a(a);
                if ((*a)->head->index == last_index)
                    break;
            }
        }
        push_a(a, b);
    }
}

