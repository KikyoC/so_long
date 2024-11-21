/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:23:17 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/19 15:37:19 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*check(t_map *map, t_player *player)
{
	if (!is_rect(map))
		return ("Map is not rectangular");
	if (!check_border(map))
		return ("Borders of the map aren't 1");
	if (!check_elements(map))
		return ("Elements aren't good. Verify that you have 1 Spawn Position,"
			"1 Exit Position and at least 1 Collectible Position");
	if (!is_solvable(map, player))
		return ("There is no way to solve the map. Check your map");
	return (NULL);
}
