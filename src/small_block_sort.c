/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_block_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:27:13 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 17:45:38 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// functions to sort the blocks in place

// sort 2 numbers
void	sort_block_2(t_stack **b)
{
    if ((*b)->head->value > (*b)->head->next->value)
        swap_b(b);
}

// sort 3 numbers
void sort_block_3(t_stack **b)
{
    int top = (*b)->head->value;
    int second = (*b)->head->next->value;
    int third = (*b)->tail->value;

    // Case 1: Already sorted
    if (top < second && second < third)
        return;

    // Case 2: Top element is largest
    if (top > second && top > third)
    {
        rotate_b(b); // Bring largest to the bottom
        if (second > third)
            swap_b(b); // Swap remaining two elements if necessary
    }
    // Case 3: Second element is largest
    else if (second > top && second > third)
    {
        reverse_rotate_b(b); // Bring second to the top
        if (top > third)
            swap_b(b); // Swap top two elements if necessary
    }
    // Case 4: Third element is largest
    else if (third > top && third > second)
    {
        if (top > second)
            swap_b(b); // Swap top two elements
    }
}

// sort 4 numbers in stack B with the help of stack A
void sort_block_4(t_stack **b)
{
    int top = (*b)->head->value;
    int second = (*b)->head->next->value;
    int third = (*b)->head->next->next->value;
    int fourth = (*b)->tail->value;

    // Case 1: If already sorted
    if (top < second && second < third && third < fourth)
        return;

    // Case 2: If the largest element is at the top
    if (top > second && top > third && top > fourth)
    {
        rotate_b(b); // Bring the largest to the bottom
        sort_block_3(b); // Sort the remaining 3 elements
    }
    // Case 3: If the largest element is at the bottom
    else if (fourth > top && fourth > second && fourth > third)
    {
        reverse_rotate_b(b); // Bring the largest to the top
        sort_block_3(b); // Sort the remaining 3 elements
        rotate_b(b); // Restore the largest to the bottom
    }
    // Case 4: If the largest element is in the second position
    else if (second > top && second > third && second > fourth)
    {
        swap_b(b); // Swap top two elements
        rotate_b(b); // Move the largest to the bottom
        sort_block_3(b); // Sort the remaining 3 elements
    }
    // Case 5: If the largest element is in the third position
    else if (third > top && third > second && third > fourth)
    {
        reverse_rotate_b(b); // Move third to top
        reverse_rotate_b(b); // Move it again to second place
        swap_b(b); // Swap the top two elements (third and fourth)
        rotate_b(b); // Move the largest to the bottom
        rotate_b(b); // Rotate once more to finalize
        sort_block_3(b); // Sort the remaining 3 elements
    }
}

// sort 5 numbers in stack B with the help of stack A
void sort_block_5(t_stack **b)
{
    int top, second, third, fourth, fifth;

    top = (*b)->head->value;
    second = (*b)->head->next->value;
    third = (*b)->head->next->next->value;
    fourth = (*b)->head->next->next->next->value;
    fifth = (*b)->tail->value;

    // Case 1: Already sorted
    if (top < second && second < third && third < fourth && fourth < fifth)
        return;

    // Case 2: If the largest is at the top
    if (top > second && top > third && top > fourth && top > fifth)
    {
        rotate_b(b); // Bring the largest to the bottom
        sort_block_4(b); // Sort the remaining 4 elements
    }
    // Case 3: If the largest is at the bottom
    else if (fifth > top && fifth > second && fifth > third && fifth > fourth)
    {
        reverse_rotate_b(b); // Bring the largest to the top
        sort_block_4(b); // Sort the remaining 4 elements
        rotate_b(b); // Restore the largest to the bottom
    }
    // Case 4: If the largest is in the second position
    else if (second > top && second > third && second > fourth && second > fifth)
    {
        swap_b(b); // Swap top two elements
        rotate_b(b); // Bring the largest to the bottom
        sort_block_4(b); // Sort the remaining 4 elements
    }
    // Case 5: If the largest is in the third position
    else if (third > top && third > second && third > fourth && third > fifth)
    {
        reverse_rotate_b(b); // Move third to the top
        reverse_rotate_b(b); // Move it again to second place
        swap_b(b); // Swap the top two elements
        rotate_b(b); // Rotate largest to the bottom
        rotate_b(b); // Rotate once more to finalize
        sort_block_4(b); // Sort the remaining 4 elements
    }
    // Case 6: If the largest is in the fourth position
    else if (fourth > top && fourth > second && fourth > third && fourth > fifth)
    {
        reverse_rotate_b(b); // Move fourth to the top
        reverse_rotate_b(b); // Move it again to second place
        reverse_rotate_b(b); // Move it again to third place
        swap_b(b); // Swap third and fourth elements
        rotate_b(b); // Rotate largest to the bottom
        rotate_b(b); // Rotate once more to finalize
        rotate_b(b); // Rotate once more to finalize
        sort_block_4(b); // Sort the remaining 4 elements 
    }
}

void small_sort_block(t_stack **b)
{
    if ((*b)->size == 2)
        sort_block_2(b);
    else if ((*b)->size == 3)
        sort_block_3(b);
    else if ((*b)->size == 4)
        sort_block_4(b);
    else if ((*b)->size == 5)
        sort_block_5(b);
}
