/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 12:59:34 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_player(t_element *old_pos, t_game *game)
{
	if (old_pos->exit)
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit, old_pos->x, old_pos->y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->grass, old_pos->x, old_pos->y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->playerp, game->player->pos->x, game->player->pos->y);
}

void	init_player(t_player *player)
{
	player->collectibles = 0;
	player->movements = 0;
}
