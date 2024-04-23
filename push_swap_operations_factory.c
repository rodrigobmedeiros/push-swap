/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_factory.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:11:38 by robernar          #+#    #+#             */
/*   Updated: 2024/04/23 15:11:40 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap_treatment(t_list **a_lst, t_list **b_lst, t_sc s_code)
{
	int	operation_counter;

	if (s_code == a)
	{
		operation_counter = op_swap(a_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "sa");
	}
	if (s_code == b)
	{
		operation_counter = op_swap(b_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "sb");
	}
	if (s_code == both)
	{
		operation_counter = op_swap(a_lst) + op_swap(b_lst);
		if (operation_counter >= 1)
			ft_printf("%s\n", "ss");
	}
	return ;
}

static void	push_treatment(t_list **a_lst, t_list **b_lst, t_sc s_code)
{
	int	operation_counter;

	if (s_code == a)
	{
		operation_counter = op_push(b_lst, a_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "pa");
	}
	else
	{
		operation_counter = op_push(a_lst, b_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "pb");
	}
	return ;
}

static void	rotate_treatment(t_list **a_lst, t_list **b_lst, t_sc s_code)
{
	int	operation_counter;

	if (s_code == a)
	{
		operation_counter = op_rotate(a_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "ra");
	}
	if (s_code == b)
	{
		operation_counter = op_rotate(b_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "rb");
	}
	if (s_code == both)
	{
		operation_counter = op_rotate(a_lst) + op_rotate(b_lst);
		if (operation_counter >= 1)
			ft_printf("%s\n", "rr");
	}
	return ;
}

static void	rev_rotate_treatment(t_list **a_lst, t_list **b_lst, t_sc s_code)
{
	int	operation_counter;

	if (s_code == a)
	{
		operation_counter = op_reverse_rotate(a_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "rra");
	}
	if (s_code == b)
	{
		operation_counter = op_reverse_rotate(b_lst);
		if (operation_counter == 1)
			ft_printf("%s\n", "rrb");
	}
	if (s_code == both)
	{
		operation_counter = op_reverse_rotate(a_lst) + op_reverse_rotate(b_lst);
		if (operation_counter >= 1)
			ft_printf("%s\n", "rrr");
	}
	return ;
}

t_opopt	operations_factory(t_op op)
{
	if (op == swap)
		return (swap_treatment);
	if (op == push)
		return (push_treatment);
	if (op == rotate)
		return (rotate_treatment);
	if (op == reverse_rotate)
		return (rev_rotate_treatment);
	return (NULL);
}
