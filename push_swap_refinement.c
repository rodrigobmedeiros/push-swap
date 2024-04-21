/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_refinement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:47:30 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:47:34 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_small_stack(t_list **a_lst, t_list **b_lst)
{
	int	init_size_a;

	(void) b_lst;
	init_size_a = ft_lstsize(*a_lst);
	while (!(is_lst_sorted(*a_lst, 1) && init_size_a == ft_lstsize(*a_lst)))
	{
		if (apply_rotate(a_lst, NULL))
			continue ;
		if (apply_swap(a_lst, NULL))
			continue ;
		if (apply_reverse_rotate(a_lst, NULL))
			continue ;
	}
	return ;
}

void	add_one_or_two_elements_to_b(t_list **a_lst, t_list **b_lst)
{
	if (ft_lstsize(*a_lst) <= 3)
		return ;
	if (ft_lstsize(*a_lst) == 4)
	{
		manage_operations(push, a_lst, b_lst, b);
		return ;
	}
	manage_operations(push, a_lst, b_lst, b);
	manage_operations(push, a_lst, b_lst, b);
	return ;
}

int	find_small_number(t_list *lst)
{
	int	min_value;

	min_value = 2147483647;
	while (lst)
	{
		if (gnd(lst) < min_value)
			min_value = gnd(lst);
		lst = lst->next;
	}
	return (min_value);
}

void	apply_n_rotate(t_list **lst, int n, t_op op)
{
	int	count;

	count = 0;
	while (count < n)
	{
		if (op == rotate)
			manage_operations(rotate, lst, NULL, a);
		if (op == reverse_rotate)
			manage_operations(reverse_rotate, lst, NULL, a);
		count++;
	}
}

void	apply_rotations_if_needed(t_list **lst, int min_value)
{
	int		lst_size;
	int		half_lst_size;
	int		min_position;
	t_list	*temp;

	lst_size = ft_lstsize(*lst);
	half_lst_size = lst_size / 2;
	min_position = 0;
	temp = *lst;
	while (temp)
	{
		min_position++;
		if (min_value == gnd(temp))
			break ;
		temp = temp->next;
	}
	if (min_position == lst_size)
		return ;
	if (min_position > half_lst_size)
		apply_n_rotate(lst, lst_size - min_position, rotate);
	else
		apply_n_rotate(lst, min_position, reverse_rotate);
	return ;
}
