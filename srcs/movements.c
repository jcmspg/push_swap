/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:26:08 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/04 20:43:47 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void swap_a(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void swap_b(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void swap_s(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void reverse_ro_ab(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
