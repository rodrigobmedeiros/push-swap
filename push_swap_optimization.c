/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:47:30 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:47:34 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_rotate_to_b(t_list **a_lst, t_list **b_lst, t_op op)
{
	int	count;
	int count_back;

	count = 0;
	while (1)
	{
		if (apply_push_b(a_lst, b_lst))
			break ;
		count++;
		if (op == rotate)
			op_rotate(b_lst);
		else
			op_reverse_rotate(b_lst);
	}
	count_back = count;
	while (count_back > 0)
	{
		if (op == rotate)
			op_reverse_rotate(b_lst);
		else
			op_rotate(b_lst);
		count_back--;
	}
	return (count);
}

int	count_rotate_to_a(t_list **a_lst, t_list **b_lst, t_op op)
{
	int	count;
	int count_back;

	count = 0;
	while (1)
	{
		if (apply_push_a(a_lst, b_lst))
			break ;
		count++;
		if (op == rotate)
			op_rotate(a_lst);
		else
			op_reverse_rotate(a_lst);
	}
	count_back = count;
	while (count_back > 0)
	{
		if (op == rotate)
			op_reverse_rotate(a_lst);
		else
			op_rotate(a_lst);
		count_back--;
	}
	return (count);
}

t_op	manage_rotates(t_list **a_lst, t_list**b_lst, t_sc stack)
{
	int count_rotate;
	int count_reverse_rotate;

	if (stack == a)
	{
		count_rotate = count_rotate_to_a(a_lst, b_lst, rotate);
		count_reverse_rotate = count_rotate_to_a(a_lst, b_lst, reverse_rotate);
	}
	else
	{
		count_rotate = count_rotate_to_b(a_lst, b_lst, rotate);
		count_reverse_rotate = count_rotate_to_b(a_lst, b_lst, reverse_rotate);
	}
	if (count_rotate <= count_reverse_rotate)
		return (rotate);
	else
		return (reverse_rotate);
}
