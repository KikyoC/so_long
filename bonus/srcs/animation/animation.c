/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:36 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:49:29 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	animate_player(t_game *game)
{
	t_element	*pos;

	pos = game->player->pos;
	if (game->fps <= 2000)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[0], pos->x, pos->y);
	else if (game->fps <= 4000)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[1], pos->x, pos->y);
	else if (game->fps <= 6000)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[2], pos->x, pos->y);
	else if (game->fps <= 8000)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[3], pos->x, pos->y);
	else if (game->fps <= 10000)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[4], pos->x, pos->y);
}

void	animate_portal(t_game *game)
{
	int			(*f)(void *ptr, void *win, void *img, int x, int y);
	t_element	*exit;

	exit = game->exit;
	f = mlx_put_image_to_window;
	if (game->fps <= 1000)
		f(game->mlx, game->window, game->exitp->frames[0], exit->x, exit->y);
	else if (game->fps <= 2000)
		f(game->mlx, game->window, game->exitp->frames[1], exit->x, exit->y);
	else if (game->fps <= 3000)
		f(game->mlx, game->window, game->exitp->frames[2], exit->x, exit->y);
	else if (game->fps <= 4000)
		f(game->mlx, game->window, game->exitp->frames[3], exit->x, exit->y);
	else if (game->fps <= 5000)
		f(game->mlx, game->window, game->exitp->frames[4], exit->x, exit->y);
	else if (game->fps <= 6000)
		f(game->mlx, game->window, game->exitp->frames[5], exit->x, exit->y);
	else if (game->fps <= 7000)
		f(game->mlx, game->window, game->exitp->frames[6], exit->x, exit->y);
	else if (game->fps <= 8000)
		f(game->mlx, game->window, game->exitp->frames[7], exit->x, exit->y);
	else if (game->fps <= 9000)
		f(game->mlx, game->window, game->exitp->frames[8], exit->x, exit->y);
}

void	animate_collectible(t_game *game, t_element *e)
{
	int			(*f)(void *ptr, void *win, void *img, int x, int y);

	f = mlx_put_image_to_window;
	if (game->fps <= 1000)
		f(game->mlx, game->window, game->collectible->frames[0], e->x, e->y);
	else if (game->fps <= 2000)
		f(game->mlx, game->window, game->collectible->frames[1], e->x, e->y);
	else if (game->fps <= 3000)
		f(game->mlx, game->window, game->collectible->frames[2], e->x, e->y);
	else if (game->fps <= 4000)
		f(game->mlx, game->window, game->collectible->frames[3], e->x, e->y);
	else if (game->fps <= 5000)
		f(game->mlx, game->window, game->collectible->frames[4], e->x, e->y);
	else if (game->fps <= 6000)
		f(game->mlx, game->window, game->collectible->frames[5], e->x, e->y);
	else if (game->fps <= 7000)
		f(game->mlx, game->window, game->collectible->frames[6], e->x, e->y);
	else if (game->fps <= 8000)
		f(game->mlx, game->window, game->collectible->frames[7], e->x, e->y);
	else if (game->fps <= 9000)
		f(game->mlx, game->window, game->collectible->frames[8], e->x, e->y);
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

void	animate_patrol(t_game *game)
{
	int			(*f)(void *ptr, void *win, void *img, int x, int y);
	t_element	*e;

	e = game->map->first->next->first->next;
	f = mlx_put_image_to_window;
	if (game->fps <= 1000)
		f(game->mlx, game->window, game->patrolp->frames[0], e->x, e->y);
	else if (game->fps <= 2000)
		f(game->mlx, game->window, game->patrolp->frames[1], e->x, e->y);
	else if (game->fps <= 3000)
		f(game->mlx, game->window, game->patrolp->frames[2], e->x, e->y);
	else if (game->fps <= 4000)
		f(game->mlx, game->window, game->patrolp->frames[0], e->x, e->y);
	else if (game->fps <= 5000)
		f(game->mlx, game->window, game->patrolp->frames[1], e->x, e->y);
	else if (game->fps <= 6000)
		f(game->mlx, game->window, game->patrolp->frames[2], e->x, e->y);
	else if (game->fps <= 7000)
		f(game->mlx, game->window, game->patrolp->frames[0], e->x, e->y);
	else if (game->fps <= 8000)
		f(game->mlx, game->window, game->patrolp->frames[1], e->x, e->y);
	else if (game->fps <= 9000)
		f(game->mlx, game->window, game->patrolp->frames[2], e->x, e->y);
}
