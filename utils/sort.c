/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:56:01 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/14 11:21:30 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_element	*current;

	current = stack->top;
	while (current)
	{
		if (!current->prev)
		{
			current = current->next;
			continue ;
		}
		else if (current->prev->index > current->index)
			return (0);
		current = current->next;
	}
	return (1);
}
