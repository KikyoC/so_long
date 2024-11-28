/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:17:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:49:25 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	delete_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->player)
		free(game->player);
	if (game->map)
		free_map(game->map);
	if (game->playerp)
		free_animation(game, game->playerp, 5);
	if (game->grass)
		mlx_destroy_image(game->mlx, game->grass);
	if (game->collectible)
		free_animation(game, game->collectible, 9);
	if (game->patrolp)
		free_animation(game, game->patrolp, 3);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		free_animation(game, game->exitp, 9);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	return (1);
}
