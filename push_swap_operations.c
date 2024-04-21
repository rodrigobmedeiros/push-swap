/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:43:31 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:43:36 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	op_swap(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;
	int		lst_size;

	lst_size = ft_lstsize(*lst);
	if (lst_size < 2)
		return (0);
	last = ft_lstpop(lst);
	before_last = ft_lstpop(lst);
	last->next = before_last;
	if (!lst || !*lst)
	{
		*lst = last;
		return (1);
	}
	ft_lstlast(*lst)->next = last;
	return (1);
}

int	op_push(t_list **from, t_list **to)
{
	t_list	*last_from;
	t_list	*last_to;

	if (!from || !*from)
		return (0);
	last_from = ft_lstpop(from);
	if (!to || !*to)
	{
		*to = last_from;
		return (1);
	}
	last_to = ft_lstlast(*to);
	last_to->next = last_from;
	return (1);
}

int	op_reverse_rotate(t_list **lst)
{
	t_list	*first;

	if (!lst || !*lst)
		return (0);
	if (ft_lstsize(*lst) == 1)
		return (0);
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	ft_lstadd_back(lst, first);
	return (1);
}

int	op_rotate(t_list **lst)
{
	t_list	*last;

	if (!lst || !*lst)
		return (0);
	if (ft_lstsize(*lst) == 1)
		return (0);
	last = ft_lstpop(lst);
	ft_lstadd_front(lst, last);
	return (1);
}

void	manage_operations(t_op op, t_list **a_lst, t_list **b_lst, t_sc s_code)
{
	int	operation_counter;

	if (op == swap)
	{
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
	}
	if (op == push)
	{
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
	}
	if (op == rotate)
	{
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
	}
	if (op == reverse_rotate)
	{
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
	}
}
