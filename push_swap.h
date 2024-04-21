#include "./libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
enum StackCode {
    a,
    b,
    both
};
enum OpName {
    swap,
    push,
    rotate,
    reverse_rotate
};
int apply_rotate(t_list **a_lst, t_list **b_lst);
int apply_reverse_rotate(t_list **a_lst, t_list **b_lst);
int apply_swap(t_list **a_lst, t_list **b_lst);
int apply_push(t_list **a_lst, t_list **b_lst);
int op_swap(t_list **lst);
int op_push(t_list **from, t_list **to);
int op_rotate(t_list **lst);
int op_reverse_rotate(t_list **lst);
int get_node_content(t_list *lst);
int is_lst_sorted(t_list *lst, int asc);
int find_small_number(t_list *lst);
void    manage_operations(enum OpName op_name, t_list **a_lst, t_list **b_lst, enum StackCode stack_code);
void    print_reverse_lst(t_list *lst, int lst_size, char *text);
void    clean_lst_content(void *content);
void    verify_input_numbers_type(int num, char *argv, int *arr);
void    verify_repeated_numbers(int num, int *arr, int start, int size);
void    verify_out_of_range_int_numbers(char *num, int *arr);
void    push_item_to_b(t_list **a_lst, t_list**b_lst);
void    push_items_to_a(t_list **a_lst, t_list **b_lst);
void    sort_small_stack(t_list **a_lst, t_list **b_lst);
void    add_one_or_two_elements_to_b(t_list **a_lst, t_list **b_lst);
void    apply_rotations_if_needed(t_list **lst, int min_value);
#endif