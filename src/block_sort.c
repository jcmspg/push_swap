/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/01 22:55:03 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void selection_sort(t_stack **a, t_stack **b)
{
    printf("Selection sort\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");
}

void sort_p(t_stack **a, t_stack **b)
{
    printf("Sort P\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");
}

void sort_partitions(t_stack **a, t_stack **b)
{
    int i;
    int j;
    int size;


    i = 1;
    while (i <= (*a)->partitions)
    {
        size = count_size(i, a);
        j = 0;
        while ((*a)->head->partition != i)
            rotate_a(a);
        if ((*a)->head->partition == i)
        {
            while (j < size)
            {
                push_b(a, b);
                j++;
            }
        }
        i++;
    }
}



void block_sort(t_stack **a, t_stack **b)
{
    int i;
    int total_partitions;

    if (*a == NULL || (*a)->head == NULL)
        return ;

    (*a)->partitions = n_partitions(*a);
    total_partitions = (*a)->partitions;
    i = total_partitions; 

    while (i > 0)
    {
        push_partition(a, b, i);
        i--;
    }

    // now push partitions back to stack A sorting them, starting from the smallest
    while (i < total_partitions)
    {
        lazy_sort(a, b);
        i++;
    }
}
