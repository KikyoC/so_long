/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:33 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 09:31:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	current_rank(t_stack *stack, int nbr)
{
	int			i;
	t_element	*current;

	i = 0;
	current = stack->top;
	while (current)
	{
		if (current->nbr == nbr)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

int	lower(t_stack *stack)
{
	int			low;
	t_element	*current;

	low = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->nbr < low)
			low = current->nbr;
		current = current->next;
	}
	return (low);
}

int	bigger(t_stack *stack)
{
	int			big;
	t_element	*current;

	big = INT_MIN;
	current = stack->top;
	while (current)
	{
		if (current->nbr > big)
			big = current->nbr;
		current = current->next;
	}
	return (big);
}
