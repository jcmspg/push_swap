/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/05 22:37:43 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void block_sort(t_stack **a, t_stack **b)
{
    int i;
    int total_partitions;
    int lowest_cost_partition;
    int lowest_cost;
    int cost;
    int *pushed;

    if (*a == NULL || (*a)->head == NULL)
        return ;

    (*a)->partitions = n_partitions(*a);
    total_partitions = (*a)->partitions;
    
  //  printf("Partitions: %d\n", total_partitions);
    
    pushed = (int *)malloc(sizeof(int) * total_partitions + 1);
    ft_memset(pushed, 0, total_partitions + 1);

    while (total_partitions > 0)
    {
        lowest_cost_partition = -1;
        lowest_cost = INT_MAX;
        i = 1;

    //    printf("Total partitions left to check: %d\n", total_partitions);
        
        while (i <= total_partitions)
        {
            if (pushed[i] == 0)
            {
                cost = calculate_cost_to_move_partition(a, i);
      //          printf("Cost to move partition %d: %d\n", i, cost);
                if (cost < lowest_cost)
                {
                    lowest_cost = cost;
                    lowest_cost_partition = i;
                }
            }
            i++;
        }
   //     printf("Lowest cost partition: %d\n", lowest_cost_partition);
        if (lowest_cost_partition != -1)
        {
            push_partition(a, b, lowest_cost_partition);
     //       printf("Pushed partition %d to B\n", lowest_cost_partition);
            pushed[lowest_cost_partition] = 1;
            total_partitions--;
    //        printf("Partitions left: %d\n", total_partitions);
        }
        else
        {
   //         printf("Error: no more partitions to push\n");
            break;
        }
    }
    free(pushed);
}
