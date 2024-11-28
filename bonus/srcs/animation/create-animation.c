/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create-animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:32:10 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 15:06:21 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

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
		return (free_animation(game, res, 0));
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
		return (free_animation(game, res, 5));
	res->current_frame = 0;
	return (res);
}

void	fill_exit_animation(t_animation *animation, t_game *game)
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
		return (free_animation(game, res, 0));
	fill_exit_animation(res, game);
	if (!res->frames[0] || !res->frames[1] || !res->frames[2]
		|| !res->frames[3] || !res->frames[4] || !res->frames[5]
		|| !res->frames[6] || !res->frames[7] || !res->frames[8])
		return (free_animation(game, res, 9));
	return (res);
}

t_animation	*create_coin_animation(t_game *game)
{
	t_animation	*res;
	void		*(*f)(void *mlx, char *path, int *w, int *h);
	int			i;

	f = mlx_xpm_file_to_image;
	res = ft_calloc(1, sizeof(t_animation));
	if (!res)
		return (NULL);
	res->frames = ft_calloc(10, sizeof(void *));
	if (!res->frames)
		return (free_animation(game, res, 0));
	res->frames[0] = f(game->mlx, "textures/coin/coin1.xpm", &i, &i);
	res->frames[1] = f(game->mlx, "textures/coin/coin2.xpm", &i, &i);
	res->frames[2] = f(game->mlx, "textures/coin/coin3.xpm", &i, &i);
	res->frames[3] = f(game->mlx, "textures/coin/coin4.xpm", &i, &i);
	res->frames[4] = f(game->mlx, "textures/coin/coin5.xpm", &i, &i);
	res->frames[5] = f(game->mlx, "textures/coin/coin6.xpm", &i, &i);
	res->frames[6] = f(game->mlx, "textures/coin/coin7.xpm", &i, &i);
	res->frames[7] = f(game->mlx, "textures/coin/coin8.xpm", &i, &i);
	res->frames[8] = f(game->mlx, "textures/coin/coin9.xpm", &i, &i);
	if (!res->frames[0] || !res->frames[1] || !res->frames[2] || !res->frames[3]
		|| !res->frames[4] || !res->frames[5] || !res->frames[6]
		|| !res->frames[7] || !res->frames[8])
		return (free_animation(game, res, 9));
	return (res);
}

t_animation	*create_patrol_animation(t_game *game)
{
	t_animation	*res;
	void		*(*f)(void *mlx, char *path, int *w, int *h);
	int			i;

	f = mlx_xpm_file_to_image;
	res = ft_calloc(1, sizeof(t_animation));
	if (!res)
		return (NULL);
	res->frames = ft_calloc(4, sizeof(void *));
	if (!res->frames)
		return (free_animation(game, res, 0));
	res->frames[0] = f(game->mlx, "textures/patrol/patrol1.xpm", &i, &i);
	res->frames[1] = f(game->mlx, "textures/patrol/patrol2.xpm", &i, &i);
	res->frames[2] = f(game->mlx, "textures/patrol/patrol3.xpm", &i, &i);
	if (!res->frames[0] || !res->frames[1] || !res->frames[2])
		return (free_animation(game, res, 3));
	return (res);
}
