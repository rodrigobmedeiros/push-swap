#include "push_swap.h"

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
    add_one_or_two_elements_to_b(&a_lst, &b_lst);
    while (!(is_lst_sorted(a_lst, 1) && init_size_a == ft_lstsize(a_lst)))
    {
        if (ft_lstsize(a_lst) <= 3)
        {
            sort_small_stack(&a_lst, &b_lst);
            print_reverse_lst(a_lst, ft_lstsize(a_lst), "a");
            push_items_to_a(&a_lst, &b_lst);
            apply_rotations_if_needed(&a_lst, find_small_number(a_lst));
            break ;
        }
        push_item_to_b(&a_lst, &b_lst);
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
        arr[j] = num;
        i++;
    }
    push_swap(arr, size);
    free(arr);
    return (0);
}