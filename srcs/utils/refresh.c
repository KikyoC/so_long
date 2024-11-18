/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:13 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:23:55 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
}
