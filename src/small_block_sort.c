/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_block_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:27:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/24 20:48:57 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// functions to sort the blocks in place
//
// it utilizes the nodes indexes to sort the block
// the indexes are assigned in ascending order
// the sorting is done in descending order
// the indexes are used to sort the block in place
// sorting is done in descending order to avoid the need to rotate the block
// when pushing it back to stack A
// 
//



// sort 2 numbers
void	sort_block_2(t_stack **a)
{
    if ((*a)->head->value > (*a)->head->next->value)
        swap_b(a);
}

// sort 3 numbers
void	sort_block_3(t_stack **a)
{
    int first;
    int second;
    int third;

    if (is_sorted(*a))
        return ;
        
    printf("\n --- \n Sorting 3 numbers\n --- \n");

    first = (*a)->head->value;
    second = (*a)->head->next->value;
    third = (*a)->head->next->next->value;
    if (first > second && first > third)
    {
        if(second > third)
        {
            swap_b(a);
            reverse_rotate_b(a);
        }
        else
            rotate_b(a);
    }
    else if (second > first && second > third)
    {
        if(first > third)
            reverse_rotate_b(a);
        else
        {
            swap_b(a);
            rotate_b(a);
        }
    }
    else
        swap_b(a);
}
       

// sort 4 numbers
void sort_block_4(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*b);

    // Push the minimum to stack B
    while ((*b)->head->value != min)
        rotate_b(b); // Rotate until min is at the top
    push_a(a, b); // Push the minimum to a

    // Now sort the remaining 3 numbers in stack A
    sort_block_3(b);

    // Push the minimum back to stack b
    push_b(a, b);
}

// sort 5 numbers
void sort_block_5(t_stack **a, t_stack **b)
{
    int min;
    int second_min;

    min = find_min(*b);
    second_min = find_second_min(*b);

    while ((*b)->size > 3)
    {
        if ((*b)->head->value == min || (*b)->head->value == second_min)
            push_a(a, b);
        else
            rotate_b(b);
    }
    sort_3(b);
    if ((*a)->head->value > (*a)->head->next->value)
    {
        push_b(a, b);
        push_b(a, b);
    }
    else
    {
        swap_a(a);
        push_b(a, b);
        push_b(a, b);
    }
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
