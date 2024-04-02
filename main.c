#include "./libft/libft.h"


void    print_lst(t_list *lst)
{
    t_list *temp;

    if (!lst)
    {
        ft_printf("Empty list!\n");
        return ;
    }
    temp = lst;
    ft_printf("%i\n", *(int *)temp->content);
    while (temp->next)
    {
        temp = temp->next;
        ft_printf("%i\n", *(int *)temp->content);
    }
    return ;    
}

int main()
{   
    int arr[5] = {-9, 2, 5, -1, 10};
    int i;

    arr[0] = -9;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = -1;
    arr[4] = 10;
    // Preciso criar duas stacks a e b
    // A b eh vazia beleza. A a eu tenho que criar com um array.
    t_list *a;
    t_list *b;
    a = (t_list *)malloc(sizeof(t_list));
    b = (t_list *)malloc(sizeof(t_list));
    a = NULL;
    b = NULL;
    i = 0;
    while (i < 5)
    {
        ft_lstadd_back(&a, ft_lstnew(&arr[i]));
        i++;
    }
    print_lst(a);
    print_lst(b);
    ft_printf("rodrigo\n");
    ft_printf("%i\n", *(int *)(a->content));
    ft_printf("%i\n", arr[0]);
}