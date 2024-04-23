/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_counter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:43:31 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:43:36 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_op_counter	init_op_counter(void)
{
	t_op_counter	op_counter;

	op_counter.ra = 0;
	op_counter.rb = 0;
	op_counter.rr = 0;
	op_counter.rra = 0;
	op_counter.rrb = 0;
	op_counter.rrr = 0;
	op_counter.total = 0;
	return (op_counter);
}


t_op_counter	apply_op_counter_b(t_list **a_lst, t_list **b_lst)
{
	t_op_counter	op_counter;
	int				count;

	op_counter = init_op_counter();
	count = 0;
	while (*a_lst)
	{
		op_counter.ra = count;
		op_counter.rb = 
	}












	return (op_counter);
}