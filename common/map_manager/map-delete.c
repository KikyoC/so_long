/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:56:12 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:22:38 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* free_row:
*	Take a row as parameter
*	Free the row and return NULL
*/
void	*free_row(t_row	*row)
{
	t_element	*current;
	t_element	*next;

	current = row->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(row);
	return (NULL);
}

/* free_row:
*	Take the map as parameter
*	Free the map and return NULL
*/
void	*free_map(t_map *map)
{
	t_row	*current;
	t_row	*next;

	current = map->first;
	while (current)
	{
		next = current->next;
		free_row(current);
		current = next;
	}
	free(map);
	return (NULL);
}
