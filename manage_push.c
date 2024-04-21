#include "push_swap.h"

static int push_a(t_list *a, t_list *b)
{
    t_list *last_b;
    t_list *last_a;

    if (ft_lstsize(b) < 1)
        return (0);
    last_a = ft_lstlast(a);
    last_b = ft_lstlast(b);
    if (get_node_content(last_a) > get_node_content(last_b))
    {
        return (0);
    }
    return (1);
}

static int push_b(t_list *a, t_list *b)
{
    (void) b;

    if (ft_lstsize(a) < 1)
        return (0);
    if (is_lst_sorted(a, 1))
        return (0);
    return (1);
}

void    push_item_to_b(t_list **a_lst, t_list**b_lst)
{
    t_list *last_a;
    t_list *last_b;

    last_a = ft_lstlast(*a_lst);
    last_b = ft_lstlast(*b_lst);
    while (1)
    {
        last_b = ft_lstlast(*b_lst);
        if (get_node_content(last_a) < get_node_content(*b_lst) && get_node_content(*b_lst) < get_node_content(last_b))
        {
            manage_operations(push, a_lst, b_lst, b);
            break;
        }
        if (get_node_content(last_a) > get_node_content(last_b) && get_node_content(last_b) > get_node_content(*b_lst))
        {
            manage_operations(push, a_lst, b_lst, b);
            break;
        }
        if (get_node_content(last_a) < get_node_content(*b_lst) && get_node_content(last_a) > get_node_content(last_b))
        {
            manage_operations(push, a_lst, b_lst, b);
            break;
        }
        manage_operations(rotate, a_lst, b_lst, b);
    }
    return ;
}

void    push_items_to_a(t_list **a_lst, t_list **b_lst)
{
    t_list *last_a;
    t_list *last_b;


    while (*b_lst)
    {
        while (1)
        {
            last_a = ft_lstlast(*a_lst);
            last_b = ft_lstlast(*b_lst);
            if (get_node_content(last_b) > get_node_content(*a_lst) && get_node_content(*a_lst) > get_node_content(last_a))
            {
                manage_operations(push, a_lst, b_lst, a);
                break;
            }
            if (get_node_content(last_b) < get_node_content(last_a) && get_node_content(last_a) < get_node_content(*a_lst))
            {
                manage_operations(push, a_lst, b_lst, a);
                break;
            }
            if (get_node_content(last_b) > get_node_content(*a_lst) && get_node_content(last_b) < get_node_content(last_a))
            {
                manage_operations(push, a_lst, b_lst, a);
                break;
            }
            manage_operations(rotate, a_lst, b_lst, a);
        }
    }
    return ;
}

int apply_push(t_list **a_lst, t_list **b_lst)
{
    if (push_a(*a_lst, *b_lst))
    {
        manage_operations(push, a_lst, b_lst, a);
        return (1);
    }
    if (push_b(*a_lst, *b_lst))
    {
        manage_operations(push, a_lst, b_lst, b);
        return (1);
    }
    return (0);
}