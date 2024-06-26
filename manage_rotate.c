#include "push_swap.h"

static int rotate_a(t_list *a)
{   
    t_list *first;
    t_list *last;

    if (ft_lstsize(a) < 2)
        return (0);
    last = a;
    first = ft_lstlast(a);
    if (get_node_content(first) < get_node_content(last))
        return (0);
    return (1);
}

static int rotate_b(t_list *b)
{
    t_list *first;
    t_list *last;

    if (ft_lstsize(b) < 2)
        return (0);
    last = b;
    first = ft_lstlast(b);
    if (get_node_content(first) > get_node_content(last))
        return (0);
    return (1);
}

int apply_rotation(t_list **a_lst, t_list **b_lst)
{
    if (rotate_a(*a_lst) && rotate_b(*b_lst))
    {
        manage_operations(rotate, a_lst, b_lst, both);
        return (1);
    }   
    else if (rotate_a(*a_lst))
    {
        manage_operations(rotate, a_lst, b_lst, a);
        return (1);
    } 
    else if (rotate_b(*b_lst))
    {
        manage_operations(rotate, a_lst, b_lst, b);
        return (1);
    }
    return (0);
}