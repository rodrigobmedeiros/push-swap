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