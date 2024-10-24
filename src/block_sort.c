/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/24 20:50:38 by joamiran         ###   ########.fr       */
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
    if ((*a)->partition_size > 5 && (*a)->partition_size <= 20)
        selection_sort(a, b);
    else if ((*a)->partition_size > 20)
        merge_sort_partition(a, b, (*a)->partition_size);
}



void sort_partition(t_stack **a, t_stack **b)
{
    if ((*b)->size == 1)
        push_a(a, b);
    else if ((*b)->size > 1 && (*b)->size <= 5)
        small_sort_block(a, b);

    print_stack(*b, "\n\n---Stack B---\n\n");
    //merge_back_to_a(a, b);
}

void block_sort(t_stack **a, t_stack **b)
{
    int i;

    assign_index(*a);
    set_array(a);
    block_sizer(a);
    n_partitions(*a);
    assign_partition(a);
    i = 1;

//    push_partition(a, b, i);
//    sort_partition(a, b);
//    print_stack(*b, "Stack B ");


    while (i <= (*a)->partitions)
    {
        push_partition(a, b, i);
        sort_partition(a, b);

        print_stack(*b, "Stack B ");

        i++;

        merge_back_to_a(a, b);
    }
    printf("\n---\n---\nFinal state\n---\n---\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");
}
