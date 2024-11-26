/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:36 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/26 10:39:03 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_animation	*create_player_animation(t_game *game)
{
	t_animation	*res;
	int			width;
	int			height;

	res = ft_calloc(1, sizeof(t_animation));
	if (!res)
		return (NULL);
	res->frames = ft_calloc(6, sizeof(void *));
	if (!res->frames)
		return (NULL);
	res->frames[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/player1.xpm", &width, &height);
	res->frames[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/player2.xpm", &width, &height);
	res->frames[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/player3.xpm", &width, &height);
	res->frames[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/player4.xpm", &width, &height);
	res->frames[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/player5.xpm", &width, &height);
	if (!res->frames[0] || !res->frames[1] || !res->frames[2]
		|| !res->frames[3] || !res->frames[4])
		return (free_animation(game, res));
	return (res);
}

void	fill_animation(t_animation *animation, t_game *game)
{
	int		width;
	int		height;

	animation->frames[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit1.xpm", &width, &height);
	animation->frames[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit2.xpm", &width, &height);
	animation->frames[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit3.xpm", &width, &height);
	animation->frames[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit4.xpm", &width, &height);
	animation->frames[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit5.xpm", &width, &height);
	animation->frames[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit6.xpm", &width, &height);
	animation->frames[6] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit7.xpm", &width, &height);
	animation->frames[7] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit8.xpm", &width, &height);
	animation->frames[8] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/exit9.xpm", &width, &height);
}

t_animation	*create_exit_animation(t_game *game)
{
	t_animation	*res;

	res = ft_calloc(1, sizeof(t_animation));
	if (!res)
		return (NULL);
	res->frames = ft_calloc(10, sizeof(void *));
	if (!res->frames)
		return (NULL);
	fill_animation(res, game);
	if (!res->frames[0] || !res->frames[1] || !res->frames[2]
		|| !res->frames[3] || !res->frames[4])
		return (free_animation(game, res));
	return (res);
}

void	animate_player(t_game *game)
{
	t_element	*pos;

	pos = game->player->pos;
	if (game->fps <= 36)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[0], pos->x, pos->y);
	else if (game->fps <= 72)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[1], pos->x, pos->y);
	else if (game->fps <= 108)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[2], pos->x, pos->y);
	else if (game->fps <= 144)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[3], pos->x, pos->y);
	else if (game->fps <= 180)
		mlx_put_image_to_window(game->mlx, game->window,
			game->playerp->frames[4], pos->x, pos->y);
}

void	animate_portal(t_game *game)
{
	int			(*f)(void *ptr, void *win, void *img, int x, int y);
	t_element	*exit;

	exit = game->exit;
	f = mlx_put_image_to_window;
	if (game->fps <= 20)
		f(game->mlx, game->window, game->exitp->frames[0], exit->x, exit->y);
	else if (game->fps <= 40)
		f(game->mlx, game->window, game->exitp->frames[1], exit->x, exit->y);
	else if (game->fps <= 60)
		f(game->mlx, game->window, game->exitp->frames[2], exit->x, exit->y);
	else if (game->fps <= 80)
		f(game->mlx, game->window, game->exitp->frames[3], exit->x, exit->y);
	else if (game->fps <= 100)
		f(game->mlx, game->window, game->exitp->frames[4], exit->x, exit->y);
	else if (game->fps <= 120)
		f(game->mlx, game->window, game->exitp->frames[5], exit->x, exit->y);
	else if (game->fps <= 140)
		f(game->mlx, game->window, game->exitp->frames[6], exit->x, exit->y);
	else if (game->fps <= 160)
		f(game->mlx, game->window, game->exitp->frames[7], exit->x, exit->y);
	else if (game->fps <= 180)
		f(game->mlx, game->window, game->exitp->frames[8], exit->x, exit->y);
}
