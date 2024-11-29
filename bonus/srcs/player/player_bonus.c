/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:44:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 14:28:29 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

/* move_player:
*	Take and element and the game as parameter
*	Put grass (or exit if element is exit) image at the element position
*	And put the player animation at player position
*/
void	move_player(t_element *old_pos, t_game *game)
{
	if (old_pos == game->exit)
		animate_portal(game);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass,
			old_pos->x, old_pos->y);
	animate_player(game);
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
