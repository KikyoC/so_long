/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 10:42:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_longm.h>

void	move_player(t_element *old_pos, t_game *game)
{
	if (old_pos == game->exit)
		mlx_put_image_to_window(game->mlx, game->window, game->exitp,
			game->exit->x, game->exit->y);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass,
			old_pos->x, old_pos->y);
	mlx_put_image_to_window(game->mlx, game->window, game->playerp,
		game->player->pos->x, game->player->pos->y);
}

void	init(t_game *game)
{
	game->player->collectibles = 0;
	game->player->movements = 0;
}
