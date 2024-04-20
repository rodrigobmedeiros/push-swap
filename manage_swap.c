#include "push_swap.h"

static int swap_a(t_list *a)
{
    t_list *last;
    t_list *before_last;

    if (ft_lstsize(a) < 2)
        return (0);
    last = ft_lstpop(&a);
    before_last = ft_lstpop(&a);
    if (get_node_content(last) < get_node_content(before_last))
    {
        ft_lstadd_back(&a, before_last);
        ft_lstadd_back(&a, last);
        return (0);
    }
    ft_lstadd_back(&a, before_last);
    ft_lstadd_back(&a, last);
    return (1);
}

static int swap_b(t_list *b)
{
    t_list *last;
    t_list *before_last;

    if (ft_lstsize(a) < 2)
        return (0);
    last = ft_lstpop(&b);
    before_last = ft_lstpop(&b);
    if (get_node_content(last) > get_node_content(before_last))
    {
        ft_lstadd_back(&b, before_last);
        ft_lstadd_back(&b, last);
        return (0);
    }
    ft_lstadd_back(&b, before_last);
    ft_lstadd_back(&b, last);
    return (1);
}

int apply_swap(t_list **a_lst, t_list **b_lst)
{
    if (swap_a(*a_lst) && swap_b(*b_lst))
    {
        manage_operations(swap, a_lst, b_lst, both);
        return (1);
    }   
    else if (swap_a(*a_lst))
    {
        manage_operations(swap, a_lst, b_lst, a);
        return (1);
    } 
    else if (swap_b(*b_lst))
    {
        manage_operations(swap, a_lst, b_lst, b);
        return (1);
    }
    return (0);
}

