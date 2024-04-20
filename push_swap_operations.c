#include "push_swap.h"

int op_swap(t_list **lst)
{
    t_list  *last;
    t_list  *before_last;
    int lst_size;

    lst_size = ft_lstsize(*lst);
    if (lst_size < 2)
        return (0);
    last = ft_lstpop(lst);
    before_last = ft_lstpop(lst);
    last->next = before_last;
    if (!lst || !*lst)
    {
        *lst = last;
        return (1);
    }
    ft_lstlast(*lst)->next = last;
    return (1);
}


int op_push(t_list **from, t_list **to)
{
    t_list *last_from;
    t_list *last_to;

    if (!from || !*from)
        return (0);
    last_from = ft_lstpop(from);
    if (!to || !*to)
    {
        *to = last_from;
        return (1);
    }
    last_to = ft_lstlast(*to);
    last_to->next = last_from;
    return (1);
}

int op_reverse_rotate(t_list **lst)
{
    t_list *first;

    if (!lst || !*lst)
        return (0);
    if (ft_lstsize(*lst) == 1)
        return (0);
    first = *lst;
    *lst = (*lst)->next;
    first->next = NULL;
    ft_lstadd_back(lst, first);
    return (1);
}

int op_rotate(t_list **lst)
{
    t_list *last;

    if (!lst || !*lst)
        return (0);
    if (ft_lstsize(*lst) == 1)
        return (0);
    last = ft_lstpop(lst);
    ft_lstadd_front(lst, last);
    return (1);
}

void    manage_operations(enum OpName op_name, t_list **a_lst, t_list **b_lst, enum StackCode stack_code)
{
    int operation_counter;

    if (op_name == swap)
    {
        if (stack_code == a)
        {
            operation_counter = op_swap(a_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "sa");
        }
        if (stack_code == b)
        {
            operation_counter = op_swap(b_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "sb");
        }
        if (stack_code == both)
        {
            operation_counter = op_swap(a_lst) + op_swap(b_lst);
            if (operation_counter >= 1)
                ft_printf("%s\n", "ss");
        }
    }
    if (op_name == push)
    {
        if (stack_code == a)
        {
            operation_counter = op_push(b_lst, a_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "pa");
        }
        else
        {
            operation_counter = op_push(a_lst, b_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "pb");
        }
    }
    if (op_name == rotate)
    {
        if (stack_code == a)
        {
            operation_counter = op_rotate(a_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "ra");
        }
        if (stack_code == b)
        {
            operation_counter = op_rotate(b_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "rb");
        }
        if (stack_code == both)
        {
            operation_counter = op_rotate(a_lst) + op_rotate(b_lst);
            if (operation_counter >= 1)
                ft_printf("%s\n", "rr");
        }
    }
    if (op_name == reverse_rotate)
    {
        if (stack_code == a)
        {
            operation_counter = op_reverse_rotate(a_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "rra");
        }
        if (stack_code == b)
        {
            operation_counter = op_reverse_rotate(b_lst);
            if (operation_counter == 1)
                ft_printf("%s\n", "rrb");
        }
        if (stack_code == both)
        {
            operation_counter = op_reverse_rotate(a_lst) + op_reverse_rotate(b_lst);
            if (operation_counter >= 1)
                ft_printf("%s\n", "rrr");
        }
    }
}