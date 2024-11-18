/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:22:48 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/12 13:41:01 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *original, t_stack *to_push, char *to_print)
{
	t_element	*element;

	element = original->top;
	if (!element)
		return ;
	original->top = element->next;
	element->prev = NULL;
	element->next = to_push->top;
	if (!to_push->top)
		to_push->top = element;
	else
	{
		to_push->top->prev = element;
		to_push->top = element;
	}
	if (to_print)
		ft_printf("%s\n", to_print);
}
