/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:29:23 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 12:01:18 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	solve(t_player *player)
{
	check_up(player);
	check_left(player);
	check_down(player);
	check_right(player);
}

int	is_visited(t_map *map, t_element **exit_pos)
{
	t_row		*row;
	t_element	*element;

	row = map->first;
	while (row)
	{
		element = row->first;
		while (element)
		{
			if (element->exit)
				*exit_pos = element;
			if ((element->collectible || element->exit) && !element->visited)
				return (0);
			element = element->next;
		}
		row = row->next;
	}
	return (1);
}

int	is_solvable(t_map *map, t_player *player)
{
	t_element	*pos;
	t_element	*exit_pos;

	pos = player->pos;
	exit_pos = NULL;
	solve(player);
	if (!is_visited(map, &exit_pos))
		return (0);
	exit_pos->value = 'E';
	player->pos = pos;
	player->pos->value = 'P';
	refresh_collectibles(map);
	return (1);
}
