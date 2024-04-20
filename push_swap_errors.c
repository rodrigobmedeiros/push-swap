#include "push_swap.h"

void    verify_input_numbers_type(int num, char *argv, int *arr)
{
    char *input;

    if (!(*argv))
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    input = ft_itoa(num);
    if (ft_strncmp(argv, input, ft_strlen(argv)))
    {
        free(input);
        if (arr)
            free(arr);
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    free(input);
}

void    verify_repeated_numbers(int num, int *arr, int start, int size)
{
    // int i;
    int arr_num;

    // i = 0;
    while (start < size)
    {  
        arr_num = arr[start];
        if (arr_num == num)
        {
            if (arr)
                free(arr);
            ft_putstr_fd("Error\n", 2);
            exit(1);
        }
        start++;
    }
}

void    verify_out_of_range_int_numbers(char *num, int *arr)
{
    int greater_than_int_max;
    int less_than_int_min;

    greater_than_int_max = ft_strncmp(num, "2147483647", ft_strlen(num));
    less_than_int_min = ft_strncmp(num, "-2147483648", ft_strlen(num));
    if (greater_than_int_max > 0 || less_than_int_min > 0)
    {
        if (arr)
            free(arr);
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
}