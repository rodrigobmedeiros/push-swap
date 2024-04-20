#include "push_swap.h"

void sort_small_stack(t_list **a_lst, t_list **b_lst)
{
    int init_size_a;

    init_size_a = ft_lstsize(*a_lst);
    while (!(is_lst_sorted(*a_lst, 1) && init_size_a == ft_lstsize(*a_lst)))
    {
        if (apply_rotate(a_lst, b_lst))
            continue ;
        if (apply_swap(a_lst, b_lst))
            continue ;
        if (apply_reverse_rotate(a_lst, b_lst))
            continue ;
        if (apply_push(a_lst, b_lst))
            continue ;
        if (is_lst_sorted(*a_lst, 1) && is_lst_sorted(*b_lst, 0))
        {
            manage_operations(push, a_lst, b_lst, a);
            continue ;
        }
        if (!is_lst_sorted(*b_lst, 0))
        {
            manage_operations(push, a_lst, b_lst, b);
            continue ;
        }
    }
    return;
}

void add_one_or_two_elements_to_b(t_list **a_lst, t_list **b_lst)
{
    if (ft_lstsize(*a_lst) <= 3)
        return;
    if (ft_lstsize(*a_lst) == 4)
    {
        manage_operations(push, a_lst, b_lst, b);
        return;
    }
    manage_operations(push, a_lst, b_lst, b);
    manage_operations(push, a_lst, b_lst, b);
    return;
}

void    push_item_to_b(t_list **a_lst, t_list**b_lst)
{
    t_list *last_a;
    t_list *last_b;

    last_a = ft_lstlast(*a_lst);
    last_b = ft_lstlast(*b_lst);
    while (1)
    {
        if (get_node_content(last_a) < get_node_content(*b_lst))
        {
            manage_operations(push, a_lst, b_lst, b);
            break ;
        }
        if (get_node_content(last_a) > get_node_content(last_b))
        {
            manage_operations(push, a_lst, b_lst, b);
            break ;
        }
        manage_operations(reverse_rotate, a_lst, b_lst, b);
    }
    return ;
}

void    push_items_to_a(t_list **a_lst, t_list **b_lst)
{
    t_list *last_a;
    t_list *last_b;


    while (*b_lst)
    {
        last_a = ft_lstlast(*a_lst);
        last_b = ft_lstlast(*b_lst);
        while (1)
        {
            if (get_node_content(last_b) > get_node_content(*a_lst))
            {
                manage_operations(push, a_lst, b_lst, a);
                break ;
            }
            if (get_node_content(last_b) < get_node_content(last_a))
            {
                manage_operations(push, a_lst, b_lst, a);
                break ;
            }
            manage_operations(rotate, a_lst, b_lst, a);
        }
    }
    return ;
}

int push_swap(int *arr, int size)
{
    int i;
    int init_size_a;
    t_list *a_lst;
    t_list *b_lst;

    i = 0;
    a_lst = NULL;
    b_lst = NULL;
    while (i < size)
        ft_lstadd_back(&a_lst, ft_lstnew(&arr[i++]));
    init_size_a = ft_lstsize(a_lst);
    add_one_or_two_elements_to_b(&a_lst, &b_lst); // Se tenho mais que 3 elementos em a passo 1 (se a tiver 4) ou 2 (se tiver +4).
    while (!(is_lst_sorted(a_lst, 1) && init_size_a == ft_lstsize(a_lst)))
    {
        if (ft_lstsize(a_lst) <= 3)
        {
            sort_small_stack(&a_lst, &b_lst);
            push_items_to_a(&a_lst, &b_lst);
            break ;
        }
        push_item_to_b(&a_lst, &b_lst);
    }
    print_reverse_lst(a_lst, ft_lstsize(a_lst), "a");
    ft_lstclear(&a_lst, clean_lst_content);
    ft_lstclear(&b_lst, clean_lst_content);
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    int num;
    int size;
    int *arr;

    if (argc < 2)
        return (0);
    size = argc - 1;
    arr = (int *)malloc(sizeof(int) * (size));
    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        j = argc - i - 1;
        verify_input_numbers_type(num, argv[i], arr);
        verify_repeated_numbers(num, arr, j + 1, size);
        arr[j] = num;
        i++;
    }
    push_swap(arr, size);
    free(arr);
    return (0);
}