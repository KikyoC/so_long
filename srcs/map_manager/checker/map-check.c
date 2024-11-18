/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:23:17 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:05 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check(t_map *map, t_player *player)
{
	return (is_rect(map) && check_border(map) && check_elements(map)
		&& is_solvable(map, player));
}
