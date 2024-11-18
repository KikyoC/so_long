/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:11:40 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 10:55:09 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	how_many_bytes(int i)
{
	int	res;
	int	power;

	power = 1;
	res = 1;
	while (i > power)
	{
		power *= 2;
		res++;
	}
	if (res - 1 <= 0)
		return (1);
	return (res - 1);
}

int	give_max_byte(t_stack *stack)
{
	t_element	*current;
	int			max;

	current = stack->top;
	max = 0;
	while (current)
	{
		if (how_many_bytes(current->index) > max)
			max = how_many_bytes(current->index);
		current = current->next;
	}
	return (max);
}
