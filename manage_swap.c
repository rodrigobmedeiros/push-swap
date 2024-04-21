/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:39:20 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:39:25 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	swap_a(t_list *a)
{
	t_list	*last;
	t_list	*before_last;

	if (ft_lstsize(a) < 2)
		return (0);
	last = ft_lstpop(&a);
	before_last = ft_lstpop(&a);
	if (gnd(last) < gnd(before_last))
	{
		ft_lstadd_back(&a, before_last);
		ft_lstadd_back(&a, last);
		return (0);
	}
	ft_lstadd_back(&a, before_last);
	ft_lstadd_back(&a, last);
	return (1);
}

int	apply_swap(t_list **a_lst, t_list **b_lst)
{
	(void) b_lst;
	if (swap_a(*a_lst))
	{
		manage_operations(swap, a_lst, b_lst, a);
		return (1);
	}
	return (0);
}
