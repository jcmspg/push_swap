/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/04 20:46:47 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <math.h>

typedef struct s_stack
{
	int value;
	t_node *next;
	t_node *prev;
} t_node;

typedef struct s_stack
{
	t_node *head;
	t_node *tail;
	int size;
} t_stack;

void swap(t_stack **stack);
void push(t_stack **stack1, t_stack **stack2);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

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
