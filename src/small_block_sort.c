/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_block_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:27:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/28 20:26:26 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort 2 numbers descending
void	sort_block_2(t_stack **a)
{
    if ((*a)->head->value < (*a)->head->next->value)
        swap_b(a);
    else
        return ;
}

// sort 3 numbers descending
void	sort_block_3(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->head->value;
    second = (*a)->head->next->value;
    third = (*a)->head->next->next->value;
    
    if(first > second && first > third)
    {
        if (second < third)
        {
            reverse_rotate_a(a);
            swap_a(a);
        }
    }
    else if (second > first && second > third)
    {
        if (first > third)
            swap_a(a);
        else
            rotate_a(a);
    }
    else
    {
        if (second > third)
            rotate_a(a);
        else
        {
            swap_a(a);
            reverse_rotate_a(a);
        }
    }
}

// sort 4 numbers descending
void sort_block_4(t_stack **a, t_stack **b)
{
    int max;
    max = find_max(*b);

    // Push the max to stack B
    while ((*b)->head->value != max)
        rotate_b(b); // Rotate until min is at the top
    push_a(a, b); // Push the max to a
    // Now sort the remaining 3 numbers in stack A
    sort_block_3(b);
    // Push the max back to stack b
    push_b(a, b);
}

// sort 5 numbers descending
void sort_block_5(t_stack **a, t_stack **b)
{
    int max;
    int second_max;

    max = find_max(*b);
    second_max = find_second_max(*b);

    while ((*b)->size > 3)
    {
        if ((*b)->head->value == max || (*b)->head->value == second_max)
            push_a(a, b);
        else
            rotate_b(b);
    }
    sort_3(b);
    if ((*a)->head->value > (*a)->head->next->value)
        swap_a(a);
}

// if args are 2, 3, 4 or 5, sort them
void small_sort_block(t_stack **a, t_stack **b)
{
    if ((*b)->size == 2)
        sort_block_2(b);
    else if ((*b)->size == 3)
        sort_block_3(b);
    else if ((*b)->size == 4)
        sort_block_4(a, b);
    else if ((*b)->size == 5)
        sort_block_5(a, b);
}
