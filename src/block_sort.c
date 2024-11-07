/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:40:56 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/07 18:29:37 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




//void block_sort(t_stack **a, t_stack **b)
//{
//    int i;
//    int total_partitions;
//    int lowest_cost_partition;
//    int lowest_cost;
//    int cost;
//    int *pushed;
//
//    if (*a == NULL || (*a)->head == NULL)
//        return ;
//
//    (*a)->partitions = n_partitions(*a);
//    total_partitions = (*a)->partitions;
//    
//    printf("Partitions: %d\n", total_partitions);
//    
//    pushed = (int *)malloc(sizeof(int) * total_partitions + 1);
//    ft_memset(pushed, 0, total_partitions + 1);
//
//    while (total_partitions > 0)
//    {
//        lowest_cost_partition = -1;
//        lowest_cost = INT_MAX;
//        i = 1;
//
//        printf("Total partitions left to check: %d\n", total_partitions);
//        
//        while (total_partitions > 0)
//        {
//            if (pushed[i] == 0)
//            {
//                cost = calculate_cost_to_move_partition(a, i);
//                printf("Cost to move partition %d: %d\n", i, cost);
//                if (cost < lowest_cost)
//                {
//                    lowest_cost = cost;
//                    lowest_cost_partition = i;
//                }
//            }
//            total_partitions--;
//        }
//        printf("Lowest cost partition: %d\n", lowest_cost_partition);
//        if (lowest_cost_partition != -1)
//        {
//            push_partition(a, b, lowest_cost_partition);
//            printf("Pushed partition %d to B\n", lowest_cost_partition);
//            pushed[lowest_cost_partition] = 1;
//            printf("Partitions left: %d\n", total_partitions);
//        }
//        else
//        {
//            printf("Error: no more partitions to push\n");
//            break;
//        }
//    }
//    free(pushed);
//}



//void block_sort(t_stack **a, t_stack **b)
//{
//    int i;
//    int total_partitions;
//    int lowest_cost_partition;
//    int lowest_cost;
//    int cost;
//    int *pushed;
//
//    if (*a == NULL || (*a)->head == NULL)
//        return ;
//
//    (*a)->partitions = n_partitions(*a);
//    total_partitions = (*a)->partitions;
//
//    pushed = (int *)malloc(sizeof(int) * total_partitions + 1);
//    ft_memset(pushed, 0, total_partitions + 1);
//
//    while (total_partitions > 0)
//    {
//        lowest_cost_partition = -1;
//        lowest_cost = INT_MAX;
//
//        i = 1;
//               }
//        printf("Lowest cost partition: %d\n", lowest_cost_partition);
//        total_partitions--;
//    }
//
//
//    if (lowest_cost_partition != -1)
//    {
//        push_partition(a, b, lowest_cost_partition);
//        pushed[lowest_cost_partition] = 1;
//    }
//
//
//
//

static int cheapest_partition(t_stack **a, int *pushed)
{
    int i;
    int total_partitions;
    int lowest_cost_partition;
    int lowest_cost;
    int cost;
    
    total_partitions = (*a)->partitions;
    lowest_cost_partition = -1;
    lowest_cost = INT_MAX;
    i = 1;
    while (i <= total_partitions)
    {
        if(pushed[i] == 1)
            i++;
        else
        {
            cost = calculate_cost_to_move_partition(a, i);
            if (cost < lowest_cost)
            {
                lowest_cost = cost;
                lowest_cost_partition = i;
                printf("Lowest cost partition: %d", lowest_cost_partition);
                printf("Lowest cost: %d \n", lowest_cost);
            }
            i++;
        }
    }
    return (lowest_cost_partition);
}


void block_sort(t_stack **a, t_stack **b)
{
    int total_partitions;
    int cheapest;
    int *pushed;
    
    total_partitions = (*a)->partitions;
  //  printf("Partitions: %d\n", total_partitions);

    pushed = (int *)malloc(sizeof(int) * total_partitions + 1);
    ft_memset(pushed, 0, total_partitions + 1);



    while (total_partitions > 0)
    {   

        cheapest = cheapest_partition(a, pushed);
        if (cheapest == -1)
            break;
//        printf("Cheapest partition: %d\n", cheapest);
        if (cheapest != (*a)->partitions)
        {
            push_partition(a, b, cheapest);
            
        }
        pushed[cheapest] = 1;
        total_partitions--;


    }
    merge_back(a, b);
    free(pushed);
}

