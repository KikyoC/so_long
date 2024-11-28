/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:35 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 10:20:21 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	row_len(t_row *row)
{
	int			res;
	t_element	*current;

	res = 0;
	current = row->first;
	while (current)
	{
		res++;
		current = current->next;
	}
	return (res);
}
