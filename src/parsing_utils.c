/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:36 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/28 17:32:34 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


// function to parse the arguments and store them in the stack

static int arg_checker(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    if (!check_values(argv + 1))
        return (1);
    return (0);
}

static int dup_checker(int argc, char **argv)
{
    int i;
    t_hashset *hashset;

    i = 1;
    hashset = ft_create_hash();
    if (!hashset)
        return (1);
    while (i < argc)
    {
        if (!ft_insert_hash(hashset, argv[i]))
        {
            ft_free_hash(hashset);
            return (1);
        }
        i++;
    }
    ft_free_hash(hashset);
    return (0);
}

static int parser_checker(int argc, char **argv)
{
    if (arg_checker(argc, argv))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    if (dup_checker(argc, argv))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    return (0);
}

static void free_split(char **values)
{
    int i;

    i = 0;
    if (!values)
        return ;
    while (values[i])
    {
        free(values[i]);
        i++;
    }
    free(values);
}

int parse_string(t_stack *stack_a, char *str)
{
    char **values;
    int i;
    int argc;

    values = ft_split(str, ' ');
    if (!values)
        return (1);
    i = 0;
    argc = 0;
    while (values[argc])
        argc++;
    if (parser_checker(argc, values))
    {
        free_split(values);
        return (1);
    }
    while (i < argc)
    {
        node_to_stack(stack_a, ft_atoi(values[i]));
        i++;
    }
    return (0);
}

int parse_args(t_stack *stack_a, int argc, char **argv)
{
    int i;

    i = 1;
    if (parser_checker(argc, argv))
        return (1);
    while (i < argc)
    {
        if (!is_number(argv[i]) || !is_integer(argv[i]))
        {
            ft_putstr_fd("Error.\n", 2);
            return (1);
        }
        node_to_stack(stack_a, ft_atoi(argv[i]));
        i++;
    }
    return (0);
}


int ft_parser(t_stack *stack_a, int argc, char **argv)
{
    if (argc < 2)
        return (1);
    if (argc == 2)
       return (parse_string(stack_a, argv[1]));
    else
       return (parse_args(stack_a, argc, argv));
}
