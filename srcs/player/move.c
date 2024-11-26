/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/26 10:10:00 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_player(t_element *old_pos, t_game *game)
{
	if (old_pos->exit)
		animate_portal(game);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->grass, old_pos->x, old_pos->y);
	animate_player(game);
}

void	init_player(t_player *player)
{
	player->collectibles = 0;
	player->movements = 0;
}
