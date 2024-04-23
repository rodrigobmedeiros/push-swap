/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_apply_counter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:45:05 by robernar          #+#    #+#             */
/*   Updated: 2024/04/23 14:45:08 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_opc	apply_counter_ra_rb(t_list **a_lst, t_list **b_lst)
{
	t_opc	min_counter;
	t_opc	counter;
	int		count;

	min_counter = init_op_counter();
	count = 0;
	while (count < ft_lstsize(*a_lst))
	{
		counter = counter_ra_rb(a_lst, b_lst, count++);
		if (counter.total <= min_counter.total)
			min_counter = counter;
		op_rotate(a_lst);
	}
	return (min_counter);
}

t_opc	apply_counter_ra_rrb(t_list **a_lst, t_list **b_lst)
{
	t_opc	min_counter;
	t_opc	counter;
	int		count;

	min_counter = init_op_counter();
	count = 0;
	while (count < ft_lstsize(*a_lst))
	{
		counter = counter_ra_rrb(a_lst, b_lst, count++);
		if (counter.total <= min_counter.total)
			min_counter = counter;
		op_rotate(a_lst);
	}
	return (min_counter);
}

t_opc	apply_counter_rra_rrb(t_list **a_lst, t_list **b_lst)
{
	t_opc	min_counter;
	t_opc	counter;
	int		count;

	min_counter = init_op_counter();
	count = 0;
	while (count < ft_lstsize(*a_lst))
	{
		counter = counter_rra_rrb(a_lst, b_lst, count++);
		if (counter.total <= min_counter.total)
			min_counter = counter;
		op_reverse_rotate(a_lst);
	}
	return (min_counter);
}

t_opc	apply_counter_rra_rb(t_list **a_lst, t_list **b_lst)
{
	t_opc	min_counter;
	t_opc	counter;
	int		count;

	min_counter = init_op_counter();
	count = 0;
	while (count < ft_lstsize(*a_lst))
	{
		counter = counter_rra_rb(a_lst, b_lst, count++);
		if (counter.total <= min_counter.total)
			min_counter = counter;
		op_reverse_rotate(a_lst);
	}
	return (min_counter);
}
