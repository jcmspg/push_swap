/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/23 19:57:59 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void test_stack_operations()
{
    //create stack_a and stack_b
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = new_stack();
    stack_b = new_stack();

    //populate stack_a
    node_to_stack(stack_a, 1);
    node_to_stack(stack_a, 2);
    node_to_stack(stack_a, 3);

    //populate stack_b
    node_to_stack(stack_b, 4);
    node_to_stack(stack_b, 5);
    node_to_stack(stack_b, 6);

    //print the stacks
    print_stack(stack_a, "Stack A");
    print_stack(stack_b, "Stack B");

    // Push elements onto stack_a
    push_a(&stack_a, &stack_b); // Test push_a
    print_stack(stack_a, "Stack A after push");
    print_stack(stack_b, "Stack B after push");

    // Swap the first two elements
    swap_a(&stack_a);
    print_stack(stack_a, "Stack A after swap");
    
    // Rotate stack_a
    rotate_a(&stack_a);
    print_stack(stack_a, "Stack A after rotate");

    // Reverse rotate stack_a
    reverse_rotate_a(&stack_a);
    print_stack(stack_a, "Stack A after reverse rotate");

    // Clean up
    free_stack(stack_a); // Implement stack clean-up
    free_stack(stack_b);
}

// Main function
int main()
{
    test_stack_operations();
    return (0);
}
*/





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

    print_stack(stack_a, "Stack A");
    print_stack(stack_b, "Stack B");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

