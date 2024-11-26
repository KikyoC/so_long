/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:23:17 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/26 15:12:40 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	good_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4)
		return (0);
	len--;
	return (name[len] == 'r' && name[len - 1] == 'e'
		&& name[len - 2] == 'b' && name[len - 3] == '.');
}

char	*check(t_map *map, t_player *player, char *name)
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
	if (!good_name(name))
		return ("Map is not good format. Check if file is a \".ber\" file");
	return (NULL);
}
