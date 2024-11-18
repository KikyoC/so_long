/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:29:23 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:48 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	solve(t_player *player)
{
	if (player->pos->exit)
		return (1);
	if (check_up(player))
		return (1);
	if (check_down(player))
		return (1);
	if (check_left(player))
		return (1);
	if (check_right(player))
		return (1);
	return (0);
}

int	is_solvable(t_map *map, t_player *player)
{
	t_element	*pos;

	pos = player->pos;
	if (!solve(player))
		return (0);
	player->pos->value = 'E';
	player->pos = pos;
	player->pos->value = 'P';
	refresh_collectibles(map);
	return (1);
}
