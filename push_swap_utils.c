/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:49:53 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:50:02 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	gnd(t_list *lst)
{
	return (*(int *)(lst->content));
}

void	print_reverse_lst(t_list *lst, int lst_size, char *text)
{
	t_list	*temp;
	int		*arr;
	int		i;

	if (!lst)
	{
		ft_printf("\n");
		return ;
	}
	arr = (int *)malloc(sizeof(int) * lst_size);
	i = lst_size - 1;
	temp = lst;
	while (temp)
	{
		arr[i] = gnd(temp);
		i--;
		temp = temp->next;
	}
	i = 0;
	while (i < lst_size)
		ft_printf("   %i   \n", arr[i++]);
	free(arr);
	ft_printf("-----%s\n\n", text);
	return ;
}

int	is_lst_sorted(t_list *lst, int asc)
{
	t_list	*temp;

	if (!lst)
		return (1);
	temp = lst;
	while (temp->next)
	{
		if ((gnd(temp) < gnd(temp->next)) && asc)
			return (0);
		if ((gnd(temp) > gnd(temp->next)) && !asc)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	clean_lst_content(void *content)
{
	(void) content;
	return ;
}
