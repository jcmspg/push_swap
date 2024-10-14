/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/14 16:56:16 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{

    int i;
    t_hashset *hashset;
    t_stack *stack_a;
    t_stack *stack_b;

    i = 0;
    //check if the arguments are valid
    if (argc < 2)
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }

    // check if the values are valid
    if (!check_values(argv + 1))
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }
    
    // check if there are any duplicates
    i = 1;
    hashset = ft_create_hash(); 
    
    if(!hashset)
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }
    while (i < argc)
    {
        if (!ft_insert_hash(hashset, argv[i]))
        {
            printf("duplicate found in %s\n", argv[i]);
        }
        i++;
    }
    ft_free_hash(hashset);


    // create the stacks
    // stack A
    stack_a = new_stack();

    // stack B
    stack_b = new_stack();

    // push the values into stack A
    i = 1;
    while (i < argc)
    {
        node_to_stack(stack_a, ft_atoi(argv[i]));
        i++;
    }
     
    // check if the list is sorted
    if (is_sorted(stack_a))
    {
        ft_putstr_fd("The list is already sorted\n", 1);
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    else
    {
        ft_putstr_fd("The list is not sorted\n", 1);
        free_stack(stack_a);
        free_stack(stack_b);
    }

    return (0);
}
