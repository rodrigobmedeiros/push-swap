#include "push_swap.h"

int get_node_content(t_list *lst)
{
    return (*(int *)(lst->content));
}

void    print_reverse_lst(t_list *lst, int lst_size)
{
    t_list *temp;
    int *arr;
    int i;

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
        arr[i] = get_node_content(temp);
        i--;
        temp = temp->next;
    }
    i = 0;
    while (i < lst_size)
    {
        ft_printf("%i\n", arr[i]);
        i++;
    }
    free(arr);
    return ;
}

int is_lst_sorted(t_list *lst, int asc)
{
    t_list *temp;

    if (!lst)
        return (1);
    temp = lst;
    while (temp->next)
    {
        if ((get_node_content(temp) < get_node_content(temp->next)) && asc)
            return (0);
        if ((get_node_content(temp) > get_node_content(temp->next)) && !asc)
            return (0);
        temp = temp->next;
    }
    return (1);
}


void    clean_lst_content(void *content)
{
    (void) content;
    return ;
}