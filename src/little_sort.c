/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:28:02 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 10:44:07 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *main)
{
	int	big;

	if (is_sorted(main))
		return ;
	big = bigger(main);
	if (current_rank(main, big) == 1)
		rotate(main, "ra");
	if (current_rank(main, big) == 0)
		rotate(main, "ra");
	if (main->top->index > main->top->next->index)
		swap(main, "sa");
}

void	sort_five(t_stack *main, t_stack *tmp)
{
	int	low;

	while (stack_len(main) > 3)
	{
		low = lower(main);
		if (current_rank(main, low) > stack_len(main) / 2)
			while (low != main->top->nbr)
				reverse_rotate(main, "rra");
		else
			while (low != main->top->nbr)
				rotate(main, "ra");
		push(main, tmp, "pb");
	}
	sort_three(main);
	while (tmp->top)
		push(tmp, main, "pa");
}
