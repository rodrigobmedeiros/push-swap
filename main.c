#include "push_swap.h"

int push_swap(int *arr, int size)
{   
    // int arr[9] = {8, 7, 6, 4, 5, 1, 2, 3, 9};   
    int i;
    int init_size_a;
    t_list *a_lst;
    t_list *b_lst;

    i = 0;
    a_lst = NULL;
    b_lst = NULL;
    while (i < size)
    {
        ft_lstadd_back(&a_lst, ft_lstnew(&arr[i]));
        i++;
    }
    init_size_a = ft_lstsize(a_lst);
    while (!(is_lst_sorted(a_lst, 1) && init_size_a == ft_lstsize(a_lst)))
    {
        if (apply_rotation(&a_lst, &b_lst))
            continue ;
        if (apply_swap(&a_lst, &b_lst))
            continue ;
        if (apply_push(&a_lst, &b_lst))
            continue ;
        if (is_lst_sorted(a_lst, 1) && is_lst_sorted(b_lst, 0))
        {
            manage_operations(push, &a_lst, &b_lst, a);
            continue ;
        }
        if (!is_lst_sorted(b_lst, 0))
        {
            manage_operations(push, &a_lst, &b_lst, b);
            continue ;
        }
    }
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
        // verify_out_of_range_int_numbers(argv[i], arr);
        arr[j] = num;
        i++;
    }
    push_swap(arr, size);
    free(arr);
    return (0);
}