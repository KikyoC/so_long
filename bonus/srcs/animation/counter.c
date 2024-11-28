/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:24:12 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:49:32 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	update_count(t_game *game)
{
	t_element	*current;

	current = game->map->first->first;
	while (current)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall, current->x, current->y);
		current = current->next;
	}
	game->counter = ft_itoa(game->player->movements);
	if (!game->counter)
	{
		mlx_loop_end(game->mlx);
		return ;
	}
	mlx_string_put(game->mlx, game->window, 32, 32, 50, game->counter);
	free(game->counter);
}
