/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_block_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:27:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/29 19:37:15 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// sort 2 numbers descending
void	sort_block_2(t_stack **b)
{
    if ((*b)->head->value < (*b)->head->next->value)
        swap_b(b);
}

/*
// sort 3 numbers descending
void sort_block_3(t_stack **b)
{
    int first;
    int second;
    int third;

    first = (*b)->head->value;
    second = (*b)->head->next->value;
    third = (*b)->head->next->next->value;
    
    if (first < second && first < third)
    {
        if (second < third)
        {
            swap_b(b);
            reverse_rotate_b(b);
        }
        else
            rotate_b(b);
    }
    if (second < first && second < third)
    {
        if (first < third)
            reverse_rotate_b(b);
        else
        {
            swap_b(b);
            rotate_b(b);
        }
    }
    else if
        (first < second)
            swap_b(b);
}


// sort 4 numbers descending
void sort_block_4(t_stack **a, t_stack **b)
{
    int max;

    max = find_max(*b);
    while((*b)->size > 3)
    {
        if ((*b)->head->value == max)
            push_a(a, b);
        else
            rotate_b(b);
    }
    rotate_a(a);
    sort_block_3(b);
}


// sort 5 numbers descending
void sort_block_5(t_stack **a, t_stack **b)
{
    int max;

    max = find_max(*b);

    while ((*b)->size > 4)
    {
        if ((*b)->head->value == max)
            push_a(a, b);
        else
            rotate_b(b);
    }
    rotate_a(a);
    sort_block_4(a, b);
}

*/



// sort 3 numbers
void	sort_block_3(t_stack **b)
{
    int first;
    int second;
    int third;

    if (is_reverse_sorted(*b))
        return ;

    first = (*b)->head->value;
    second = (*b)->head->next->value;
    third = (*b)->head->next->next->value;
    if (first < second && first < third)
    {
        if(second < third)
        {
            swap_b(b);
            reverse_rotate_b(b);
        }
        else
            rotate_b(b);
    }
    else if (second < first && second < third)
    {
        if(first < third)
            reverse_rotate_b(b);
        else
        {
            swap_b(b);
            rotate_b(b);
        }
    }
    else
        swap_b(b);
}
       

// sort 4 numbers
void sort_block_4(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*b);

    // Push the minimum to stack A
    while ((*b)->size > 3)
    {
        if ((*b)->head->value == min || (*b)->tail->value == min)
            if ((*b)->head->value == min)
                push_a(a, b);\
            else
                reverse_rotate_b(b);
        else
            rotate_b(b);
    }
    // Now sort the remaining 3 numbers in stack 
    sort_block_3(b);

    // Push the minimum to the bottom of stack A
    rotate_a(a);
}

// sort 5 numbers
void sort_block_5(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*b);

    while ((*b)->size > 4)
    {
        if ((*b)->head->value == min || (*b)->tail->value == min)
        {
            if ((*b)->head->value == min)
                push_a(a, b);
            else
                reverse_rotate_b(b);
        }
        else
            rotate_b(b);
    }
    rotate_a(a);
    sort_block_4(a, b);
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

