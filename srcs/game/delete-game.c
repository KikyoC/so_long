/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:17:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 10:47:20 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	delete_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->player)
		free(game->player);
	if (game->map)
		free_map(game->map);
	if (game->playerp)
		mlx_destroy_image(game->mlx, game->playerp);
	if (game->grass)
		mlx_destroy_image(game->mlx, game->grass);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	return (1);
}
