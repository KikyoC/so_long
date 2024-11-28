/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:21:33 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* move_player:
*	Take and element and the game as parameter
*	Put grass (or exit if element is exit) image at the elemnt position
*	And put the player image at player position
*/
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

/* init:
*	Take the game as parameter
*	Set default player value to 0 
*/
void	init(t_game *game)
{
	game->player->collectibles = 0;
	game->player->movements = 0;
}
