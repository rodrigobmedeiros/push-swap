/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:58:18 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:24:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_item_to_a(t_list **a_lst, t_list **b_lst)
{
	t_op	op;
	int		n_operations;

	op = manage_rotates(a_lst, b_lst, a);
	n_operations = count_rotate_to_a(a_lst, b_lst, op);
	while (n_operations > 0)
	{
		manage_operations(op, a_lst, b_lst, a);
		n_operations--;
	}
	manage_operations(push, a_lst, b_lst, a);
	return ;
}

void	push_item_to_b(t_list **a_lst, t_list**b_lst)
{
	t_op	op;
	int		n_operations;

	op = manage_rotates(a_lst, b_lst, b);
	n_operations = count_rotate_to_b(a_lst, b_lst, op);
	while (n_operations > 0)
	{
		manage_operations(op, a_lst, b_lst, b);
		n_operations--;
	}
	manage_operations(push, a_lst, b_lst, b);
	return ;
}

void	push_items_to_a(t_list **a_lst, t_list **b_lst)
{
	while (*b_lst)
	{
		push_item_to_a(a_lst, b_lst);
	}
	return ;
}

int	apply_push_a(t_list **a_lst, t_list **b_lst)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(*a_lst);
	last_b = ft_lstlast(*b_lst);
	if (gnc(last_b) > gnc(*a_lst) && gnc(*a_lst) > gnc(last_a))
	{
		return (1);
	}
	if (gnc(last_b) < gnc(last_a) && gnc(last_a) < gnc(*a_lst))
	{
		return (1);
	}
	if (gnc(last_b) > gnc(*a_lst) && gnc(last_b) < gnc(last_a))
	{
		return (1);
	}
	return (0);
}

int apply_push_b(t_list **a_lst, t_list **b_lst)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(*a_lst);
	last_b = ft_lstlast(*b_lst);
	if (gnc(last_a) < gnc(*b_lst) && gnc(*b_lst) < gnc(last_b))
	{
		return (1);
	}
	else if (gnc(last_a) > gnc(last_b) && gnc(last_b) > gnc(*b_lst))
	{
		return (1);
	}
	else if (gnc(last_a) < gnc(*b_lst) && gnc(last_a) > gnc(last_b))
	{
		return (1);
	}
	return (0);
}
