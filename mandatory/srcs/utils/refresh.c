/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:13 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 11:51:54 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_longm.h>

/* refresh_collectibles:
*	Take the map as parameter
*	Put all element's value who are collectible to 'C'
*/
void	refresh_collectibles(t_map *map)
{
	t_row		*row;
	t_element	*element;

	row = map->first;
	while (row)
	{
		element = row->first;
		while (element)
		{
			if (element->collectible)
				element->value = 'C';
			element = element->next;
		}
		row = row->next;
	}
	map->game->player->collectibles = 0;
}
