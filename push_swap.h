/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:52:09 by robernar          #+#    #+#             */
/*   Updated: 2024/04/21 19:52:46 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef enum e_StackCode {
	a,
	b,
	both
}	t_sc;
typedef enum e_OpName {
	swap,
	push,
	rotate,
	reverse_rotate
}	t_op;
typedef struct OperationsCounter {
	int	ra;
	int	rb;
	int rr;
	int	rra;
	int	rrb;
	int rrr;
	int total;
}	t_op_counter;
int				apply_rotate(t_list **a_lst, t_list **b_lst);
int				apply_reverse_rotate(t_list **a_lst, t_list **b_lst);
int				apply_swap(t_list **a_lst, t_list **b_lst);
int				apply_push_a(t_list **a_lst, t_list **b_lst);
int				apply_push_b(t_list **a_lst, t_list **b_lst);
int				op_swap(t_list **lst);
int				op_push(t_list **from, t_list **to);
int				op_rotate(t_list **lst);
int				op_reverse_rotate(t_list **lst);
int				gnc(t_list *lst);
int				is_lst_sorted(t_list *lst, int asc);
int				find_small_number(t_list *lst);
int				count_rotate_to_b(t_list **a_lst, t_list **b_lst, t_op op);
int				count_rotate_to_a(t_list **a_lst, t_list **b_lst, t_op op);
void			manage_operations(t_op op, t_list **a_lst, t_list **b_lst, t_sc s_code);
void			print_reverse_lst(t_list *lst, int lst_size, char *text);
void			clean_lst_content(void *content);
void			verify_input_numbers_type(int num, char *argv, int *arr);
void			verify_repeated_numbers(int num, int *arr, int start, int size);
void			verify_out_of_range_int_numbers(char *num, int *arr);
void			push_item_to_b(t_list **a_lst, t_list**b_lst);
void			push_items_to_a(t_list **a_lst, t_list **b_lst);
void			sort_small_stack(t_list **a_lst, t_list **b_lst);
void			add_one_or_two_elements_to_b(t_list **a_lst, t_list **b_lst);
void			apply_rotations_if_needed(t_list **lst, int min_value);
t_op			manage_rotates(t_list **a_lst, t_list**b_lst, t_sc stack);
t_op_counter	init_op_counter(void);
#endif
