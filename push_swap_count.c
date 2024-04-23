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

t_opc	counter_ra_rb(t_list **a_lst, t_list **b_lst, int count)
{
	t_opc	op_counter;

	op_counter = init_op_counter();
	op_counter.ra = count;
	op_counter.rb = count_rotate_to_b(a_lst, b_lst, rotate);
	if (op_counter.ra < op_counter.rb)
		op_counter.rr = op_counter.ra;
	else
		op_counter.rr = op_counter.rb;
	op_counter.ra = op_counter.ra - op_counter.rr;
	op_counter.rb = op_counter.rb - op_counter.rr;
	op_counter.total = op_counter.rr + op_counter.ra + op_counter.rb;
	return (op_counter);
}

t_opc	counter_rra_rrb(t_list **a_lst, t_list **b_lst, int count)
{
	t_opc	op_counter;

	op_counter = init_op_counter();
	op_counter.rra = count;
	op_counter.rrb = count_rotate_to_b(a_lst, b_lst, reverse_rotate);
	if (op_counter.rra < op_counter.rrb)
		op_counter.rrr = op_counter.rra;
	else
		op_counter.rrr = op_counter.rrb;
	op_counter.rra = op_counter.rra - op_counter.rrr;
	op_counter.rrb = op_counter.rrb - op_counter.rrr;
	op_counter.total = op_counter.rrr + op_counter.rra + op_counter.rrb;
	return (op_counter);
}

t_opc	counter_ra_rrb(t_list **a_lst, t_list **b_lst, int count)
{
	t_opc	op_counter;

	op_counter = init_op_counter();
	op_counter.ra = count;
	op_counter.rrb = count_rotate_to_b(a_lst, b_lst, reverse_rotate);
	op_counter.total = op_counter.ra + op_counter.rrb;
	return (op_counter);
}

t_opc	counter_rra_rb(t_list **a_lst, t_list **b_lst, int count)
{
	t_opc	op_counter;

	op_counter = init_op_counter();
	op_counter.rra = count;
	op_counter.rb = count_rotate_to_b(a_lst, b_lst, rotate);
	op_counter.total = op_counter.rra + op_counter.rb;
	return (op_counter);
}

t_opc	get_min_operations_b(t_list **a_lst, t_list **b_lst)
{
	t_opc	min_counter;
	t_opc	counter;

	min_counter = init_op_counter();
	counter = apply_counter_ra_rb(a_lst, b_lst);
	if (counter.total <= min_counter.total)
		min_counter = counter;
	counter = apply_counter_ra_rrb(a_lst, b_lst);
	if (counter.total <= min_counter.total)
		min_counter = counter;
	counter = apply_counter_rra_rrb(a_lst, b_lst);
	if (counter.total <= min_counter.total)
		min_counter = counter;
	counter = apply_counter_rra_rb(a_lst, b_lst);
	if (counter.total <= min_counter.total)
		min_counter = counter;
	return (min_counter);
}
