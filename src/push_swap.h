/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/10 20:00:23 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <math.h>

# include "../inc/lib_ft/libft.h"

# define HASH_SIZE 1000



// node to store integers in linked list
typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
} t_node;

// stack for sorting
typedef struct s_stack
{
	t_node *head;
	t_node *tail;
	int size;
} t_stack;

// node to store strings in linked list for hashset
typedef struct n_node
{
    char *key;
    struct n_node *next;
} t_hashnode;

// hashset will have an array of these nodes
typedef struct s_hashset
{
    t_hashnode **array; // array of linked lists
} t_hashset;

// movement functions
void swap(t_stack **stack);
void push(t_stack **stack1, t_stack **stack2);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

// stack functions
void push_a(t_stack **a, t_stack **b);
void push_b(t_stack **a, t_stack **b);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
void rotate_ab(t_stack **a, t_stack **b);
void swap_a(t_stack **a);
void swap_b(t_stack **b);
void swap_s(t_stack **a, t_stack **b);
void reverse_rotate_a(t_stack **a);
void reverse_rotate_b(t_stack **b);
void reverse_ro_ab(t_stack **a, t_stack **b);

// stack creation functions


// check functions
int is_number(char *str);
int is_integer(char *str);
int is_duplicate(t_stack *stack, int value);
int check_values(char **values);
int is_sorted(t_stack *stack);

// hash functions
unsigned int ft_hash(char *str);
t_hashset *ft_create_hash();
int ft_insert_hash(t_hashset *hashset, char *key);
void ft_free_hash(t_hashset *hashset);
int ft_duplicate(t_hashset *hashset, char *key);




#endif
