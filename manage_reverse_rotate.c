/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:34:32 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:34:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	reverse_rotate_a(t_list *a)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(a) < 2)
		return (0);
	last = a;
	first = ft_lstlast(a);
	if (gnd(first) > gnd(last))
		return (0);
	return (1);
}

int	apply_reverse_rotate(t_list **a_lst, t_list **b_lst)
{
	(void) b_lst;
	if (reverse_rotate_a(*a_lst))
	{
		manage_operations(reverse_rotate, a_lst, b_lst, a);
		return (1);
	}
	return (0);
}
