/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/24 20:51:10 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = new_stack();
    stack_b = new_stack();
    if (ft_parser(stack_a, argc, argv))
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    
    print_stack(stack_a, "Stack A");

    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (0);
    }
    else 
    {
        if (stack_a->size > 0 && stack_a->size <=5)
            ft_small_sort(&stack_a, &stack_b);
        else
            block_sort(&stack_a, &stack_b);
    }
    //print the partition size
    printf("Partition size: %d\n", stack_a->partition_size);
    //print the nyumber of partitions
    printf("Number of partitions: %d\n", stack_a->partitions);

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

