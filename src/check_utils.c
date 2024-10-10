/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:16:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/10 19:03:06 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// functions to check if values are valid

// checks if the value is a number
int	is_number(char *str)
{
    int	i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

// checks if the value is an integer
// if it is, it returns 1
// if it is not, it returns 0
int	is_integer(char *str)
{
    long long int	nbr;

    nbr = ft_atoi(str);
    if (nbr > INT_MAX || nbr < INT_MIN)
        return (0);
    return (1);
}

// checks if there are any duplicates in the stack
// it reads an array, and stores values in a buffer to compare them
// if there are duplicates, it returns 0
// if there are no duplicates, it returns 1


// function to check if the values are valid
// if they are, it returns 1
// if they are not, it returns 0
int check_values(char **values)
{
    int	i;

    i = 0;
    while (values[i])
    {
        if (!is_number(values[i]) || !is_integer(values[i]))
        {
            ft_putstr_fd("Error, values are not valid.\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

// checks if all the values of the stack are sorted
// if they are, it returns 1
// if they are not, it returns 0
int	is_sorted(t_stack *stack)
{
    t_node  *current;
    t_node  *next;

    current = stack->head;
    next = current->next;

    while (next)
    {
        if (current->value > next->value)
            return (0);
        current = next;
        next = next->next;
    }
    return (1);
}
