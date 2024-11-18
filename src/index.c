/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:27:41 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 13:24:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *stack, int size)
{
	t_element	*current;
	t_element	*hight;
	int			last;

	while (--size)
	{
		current = stack->top;
		last = -2147483648;
		while (current)
		{
			if (current->nbr == -2147483648 && !current->index)
				current->index = 1;
			if (current->nbr > last && !current->index)
			{
				last = current->nbr;
				hight = current;
				current = stack->top;
			}
			else
				current = current->next;
		}
		if (hight)
			hight->index = size;
	}
}

void	radix_tmp_sort(t_stack *main, t_stack *tmp, int bits, int actual)
{
	int	size;

	size = stack_len(tmp);
	while (size-- && actual <= bits && !is_sorted(main))
	{
		if (tmp->top->index >> actual & 1)
			push(tmp, main, "pa");
		else
			rotate(tmp, "rb");
	}
	if (is_sorted(main))
		while (tmp->top)
			push(tmp, main, "pa");
}

void	radix(t_stack *main, t_stack *tmp)
{
	int			bits;
	int			actual;
	int			i;

	bits = give_max_byte(main);
	actual = 0;
	while (actual <= bits)
	{
		i = stack_len(main);
		while (i-- && !is_sorted(main))
		{
			if (main->top->index >> actual & 1)
				rotate(main, "ra");
			else
				push(main, tmp, "pb");
		}
		radix_tmp_sort(main, tmp, bits, actual + 1);
		actual ++;
	}
}

void	sort(t_stack *main, t_stack *tmp)
{
	if (stack_len(main) == 0)
		return ;
	set_index(main, stack_len(main));
	if (stack_len(main) <= 5)
		sort_five(main, tmp);
	else
		radix(main, tmp);
}
