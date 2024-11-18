/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:18 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/14 11:21:05 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack, char *to_print)
{
	t_element	*top;
	t_element	*last;

	if (stack_len(stack) < 2)
		return ;
	top = stack->top;
	last = stack_last(stack);
	last->prev->next = NULL;
	last->next = top;
	last->prev = NULL;
	stack->top = last;
	top->prev = last;
	if (to_print)
		ft_printf("%s\n", to_print);
}
