/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:36 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 17:13:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	animate_player(t_game *game)
{
	t_element		*pos;
	struct timeval	current_time;

	pos = game->player->pos;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_sec * 1000000 + current_time.tv_usec
		> game->playerp->last_print + 200000)
	{
		game->playerp->last_print = current_time.tv_sec * 1000000
			+ current_time.tv_usec;
		game->playerp->current_frame++;
	}
	if (game->playerp->current_frame > 4)
		game->playerp->current_frame = 0;
	mlx_put_image_to_window(game->mlx, game->window,
		game->playerp->frames[game->playerp->current_frame], pos->x, pos->y);
}

void	animate_portal(t_game *game)
{
	t_element		*pos;
	struct timeval	current_time;

	pos = game->exit;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_sec * 1000000 + current_time.tv_usec
		> game->exitp->last_print + 20000)
	{
		game->exitp->last_print = current_time.tv_sec * 1000000
			+ current_time.tv_usec;
		game->exitp->current_frame++;
	}
	if (game->exitp->current_frame > 8)
		game->exitp->current_frame = 0;
	mlx_put_image_to_window(game->mlx, game->window,
		game->exitp->frames[game->exitp->current_frame], pos->x, pos->y);
}

void	animate_collectible(t_game *game, t_element *e)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_sec * 1000000 + current_time.tv_usec
		> game->collectible->last_print + 90000)
	{
		game->collectible->last_print = current_time.tv_sec * 1000000
			+ current_time.tv_usec;
		game->collectible->current_frame++;
	}
	if (game->collectible->current_frame > 8)
		game->collectible->current_frame = 0;
	mlx_put_image_to_window(game->mlx, game->window,
		game->collectible->frames[game->collectible->current_frame],
		e->x, e->y);
}

void	animate_collectibles(t_game *game)
{
	t_row		*row;
	t_element	*element;

	row = game->map->first;
	while (row)
	{
		element = row->first;
		while (element)
		{
			if (element->value == 'C')
				animate_collectible(game, element);
			element = element->next;
		}
		row = row->next;
	}
}
