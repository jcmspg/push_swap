/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/10 20:33:05 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    //check if the arguments are valid
    if (argc < 2)
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }
 
    int i;
    t_hashset *hashset;

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




    return (0);
}
