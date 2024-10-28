/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/28 20:06:37 by joamiran         ###   ########.fr       */
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

#define SMALL_SIZE_THRESHOLD 100
#define MEDIUM_SIZE_THRESHOLD 500
#define LARGE_SIZE_THRESHOLD 1000

#define MAX_BLOCK_SIZE 50
#define MIN_BLOCK_SIZE 3

// node to store integers in linked list
typedef struct s_node
{
	int value;
    int index;
    int partition;
	struct s_node *next;
	struct s_node *prev;
} t_node;

// stack for sorting
typedef struct s_stack
{
	t_node *head;
	t_node *tail;
    int *array;
	int size;
    int partitions;
    int partition_size;
    int min;
    int max;
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


// math functions
double ft_sqrt(double x);
double ft_mean(int *array, int size);
double ft_pow(double x, double y);
double ft_std_dev(int *array, int size);

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
t_node *new_node(int value);
t_stack *new_stack();
void node_to_stack(t_stack *stack, int value);
void *set_array(t_stack **stack);



// stack free functions
void free_stack(t_stack **stack);

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

// sort specific functions for 2 - 7 elements
void sort_2(t_stack **a);
void sort_3(t_stack **a);
void sort_4(t_stack **a, t_stack **b);
void sort_5(t_stack **a, t_stack **b);
void ft_small_sort(t_stack **a, t_stack **b);

// sort functions
void block_sort(t_stack **a, t_stack **b);
void merge_back_to_a(t_stack **a, t_stack **b);

void sort_partition(t_stack **a, t_stack **b);

//block sort functions
void small_sort_block(t_stack **a, t_stack **b);
void sort_block_2(t_stack **b);
void sort_block_3(t_stack **b);
void sort_block_4(t_stack **a, t_stack **b);
void sort_block_5(t_stack **a, t_stack **b);

// merge sort functions
void merge_sort_partition(t_stack **stack_a, t_stack **stack_b, int partition_size);
void merge_two_sorted_stacks(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b);

// insertion sort functions
void selection_sort(t_stack **a, t_stack **b);



// find functions
int find_min(t_stack *stack);
int find_max(t_stack *stack);
int find_second_min(t_stack *stack);
int find_second_max(t_stack *stack);
int find_nth_smallest(t_stack *stack);
int find_position(t_stack *stack, t_node *node);
t_node *find_min_node(t_stack *stack);

// parsing functions
int ft_parser(t_stack *stack_a, int argc, char **argv);

// index functions
void assign_index(t_stack *stack);
void assign_partition(t_stack **stack);

// partition functions
void block_sizer(t_stack **stack);
int n_partitions(t_stack *stack);
void push_partition(t_stack **a, t_stack **b, int block);
void move_partitions(t_stack **a, t_stack **b);

// sort B functions
void move_min_to_top(t_stack **stack_b);
void sort_b(t_stack **stack);

// debug functions
void print_stack(t_stack *stack, char *message);
void print_array(int *array, int size, char *message);
void print_partition(t_stack *stack);
void print_index(t_stack *stack);

#endif
