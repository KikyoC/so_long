/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:29:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 13:58:36 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_stack_end(t_stack *stack, t_element *element)
{
	t_element	*current;

	if (!stack->top)
	{
		stack->top = element;
		return ;
	}
	current = stack->top;
	while (current)
	{
		if (!current->next)
		{
			current->next = element;
			element->prev = current;
			break ;
		}
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_element	*element;
	t_element	*next;

	element = stack->top;
	while (element)
	{
		next = element->next;
		free(element);
		element = next;
	}
	free(stack);
}

int	stack_len(t_stack *stack)
{
	t_element	*current;
	int			i;

	current = stack->top;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_element	*stack_last(t_stack *stack)
{
	t_element	*current;

	current = stack->top;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
