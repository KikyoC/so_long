/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:08:52 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:22:33 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* put_row_end:
*	Take a row and an element as parameter
*	Put the element at the end of the row
*/
void	put_row_end(t_row *row, t_element *element)
{
	t_element	*current;

	if (!row->first)
	{
		row->first = element;
		return ;
	}
	element->row = row;
	current = row->first;
	while (current)
	{
		if (!current->next)
		{
			element->prev = current;
			current->next = element;
			break ;
		}
		current = current->next;
	}
}

/* put_map_end:
*	Take the map and an element as parameter
*	Put the element at the end of the map
*/
void	put_map_end(t_map *map, t_row *element)
{
	t_row	*current;

	if (!map->first)
	{
		map->first = element;
		return ;
	}
	current = map->first;
	while (current)
	{
		if (!current->next)
		{
			element->prev = current;
			current->next = element;
			break ;
		}
		current = current->next;
	}
}
