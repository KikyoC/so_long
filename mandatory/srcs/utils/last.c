/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:26:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 11:45:36 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_longm.h>

/* last_in_row:
*	Take a row as parameter
*	Return the last element of the row
*/
t_element	*last_in_row(t_row *row)
{
	t_element	*current;

	current = row->first;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

/* last_in_map:
*	Take the map as parameter
*	Return last row of the map
*/
t_row	*last_in_map(t_map *map)
{
	t_row	*current;

	current = map->first;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
