/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:48:41 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 17:26:56 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// sort 2 numbers
void	sort_2(t_stack **a)
{
    if ((*a)->head->value > (*a)->head->next->value)
        swap_a(a);
}

// sort 3 numbers
void	sort_3(t_stack **a)
{
    int first;
    int second;
    int third;

    if (is_sorted(*a))
        return ;

    first = (*a)->head->value;
    second = (*a)->head->next->value;
    third = (*a)->head->next->next->value;
    if (first > second && first > third)
    {
        if(second > third)
        {
            swap_a(a);
            reverse_rotate_a(a);
        }
        else
            rotate_a(a);
    }
    else if (second > first && second > third)
    {
        if(first > third)
            reverse_rotate_a(a);
        else
        {
            swap_a(a);
            rotate_a(a);
        }
    }
    else
        swap_a(a);
}
       

// sort 4 numbers
void sort_4(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*a);

    // Push the minimum to stack B
    while ((*a)->head->value != min)
        rotate_a(a); // Rotate until min is at the top
    push_b(a, b); // Push the minimum to B

    // Now sort the remaining 3 numbers in stack A
    sort_3(a);

    // Push the minimum back to stack A
    push_a(a, b);
}

// sort 5 numbers
void sort_5(t_stack **a, t_stack **b)
{
    int min;
    int second_min;

    min = find_min(*a);
    second_min = find_second_min(*a);

    while ((*a)->size > 3)
    {
        if ((*a)->head->value == min || (*a)->head->value == second_min)
            push_b(a, b);
        else
            rotate_a(a);
    }
    sort_3(a);
    if ((*b)->head->value > (*b)->head->next->value)
    {
        push_a(a, b);
        push_a(a, b);
    }
    else
    {
        rotate_b(b);
        push_a(a, b);
        push_a(a, b);
    }
}

// if args are 2, 3, 4 or 5, sort them
void ft_small_sort(t_stack **a, t_stack **b)
{
    if ((*a)->size == 2)
        sort_2(a);
    else if ((*a)->size == 3)
        sort_3(a);
    else if ((*a)->size == 4)
        sort_4(a, b);
    else if ((*a)->size == 5)
        sort_5(a, b);
}
