/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:07:54 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/14 11:21:21 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, char *to_print)
{
	t_element	*tmp;
	t_element	*tmp_2;

	if (stack_len(stack) < 2)
		return ;
	tmp = stack->top;
	tmp_2 = stack->top->next;
	tmp->next = tmp_2->next;
	tmp_2->next = tmp;
	tmp_2->prev = tmp->prev;
	tmp->prev = tmp_2;
	stack->top = tmp_2;
	if (to_print)
		ft_printf("%s\n", to_print);
}
