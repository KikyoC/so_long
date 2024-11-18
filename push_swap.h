/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:09:04 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 09:54:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_element
{
	int					nbr;
	int					index;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
}	t_stack;

int			check_args(int argc, char **argv);
void		put_stack_end(t_stack *stack, t_element *element);
void		free_stack(t_stack *stack);
void		push(t_stack *original, t_stack *to_push, char *to_print);
void		rotate(t_stack *stack, char *to_print);
void		swap(t_stack *stack, char *to_print);
void		reverse_rotate(t_stack *stack, char *to_print);
int			stack_len(t_stack *stack);
t_element	*stack_last(t_stack *stack);
int			is_sorted(t_stack *stack);
void		sort(t_stack *main, t_stack *tmp);
int			give_max_byte(t_stack *stack);
int			current_rank(t_stack *stack, int nbr);
int			lower(t_stack *stack);
int			bigger(t_stack *stack);
void		sort_five(t_stack *main, t_stack *tmp);
#endif