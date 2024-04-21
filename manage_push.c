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

void	push_item_to_b(t_list **a_lst, t_list**b_lst)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(*a_lst);
	while (1)
	{
		last_b = ft_lstlast(*b_lst);
		if (gnd(last_a) < gnd(*b_lst) && gnd(*b_lst) < gnd(last_b))
		{
			manage_operations(push, a_lst, b_lst, b);
			break ;
		}
		else if (gnd(last_a) > gnd(last_b) && gnd(last_b) > gnd(*b_lst))
		{
			manage_operations(push, a_lst, b_lst, b);
			break ;
		}
		else if (gnd(last_a) < gnd(*b_lst) && gnd(last_a) > gnd(last_b))
		{
			manage_operations(push, a_lst, b_lst, b);
			break ;
		}
		manage_operations(rotate, a_lst, b_lst, b);
	}
	return ;
}

void	push_items_to_a(t_list **a_lst, t_list **b_lst)
{
	while (*b_lst)
	{
		while (1)
		{
			if (apply_push(a_lst, b_lst))
				break ;
			manage_operations(rotate, a_lst, b_lst, a);
		}
	}
	return ;
}

int	apply_push(t_list **a_lst, t_list **b_lst)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = ft_lstlast(*a_lst);
	last_b = ft_lstlast(*b_lst);
	if (gnd(last_b) > gnd(*a_lst) && gnd(*a_lst) > gnd(last_a))
	{
		manage_operations(push, a_lst, b_lst, a);
		return (1);
	}
	if (gnd(last_b) < gnd(last_a) && gnd(last_a) < gnd(*a_lst))
	{
		manage_operations(push, a_lst, b_lst, a);
		return (1);
	}
	if (gnd(last_b) > gnd(*a_lst) && gnd(last_b) < gnd(last_a))
	{
		manage_operations(push, a_lst, b_lst, a);
		return (1);
	}
	return (0);
}
