/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:36:32 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:36:36 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	rotate_a(t_list *a)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(a) < 2)
		return (0);
	last = a;
	first = ft_lstlast(a);
	if (gnc(first) < gnc(last))
		return (0);
	return (1);
}

int	apply_rotate(t_list **a_lst, t_list **b_lst)
{
	(void) b_lst;
	if (rotate_a(*a_lst))
	{
		manage_operations(rotate, a_lst, b_lst, a);
		return (1);
	}
	return (0);
}
