/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/30 21:26:24 by joamiran         ###   ########.fr       */
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

void sort_partition(t_stack **a, t_stack **b)
{
   small_sort_block(a, b);
   while ((*b)->head != NULL)
       push_a(a, b);
   // merge_back_to_a(a, b);
}

void block_sort(t_stack **a, t_stack **b)
{
    int i;
    int total_partitions;
    (*a)->partitions = n_partitions(*a);

    total_partitions = (*a)->partitions;
    i = 1;
    while (i <= total_partitions)
    {
        push_partition(a, b, i);
        sort_partition(a, b);
        i++;
    }
   // sort the order of the partitions
//    sort_partitions(a, b);
//    merge_back_to_a(a, b);
}
