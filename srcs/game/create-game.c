/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create-game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:07:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 12:18:42 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_image(char c, t_game *game, t_element *element)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall,
			element->x, element->y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->playerp,
			element->x, element->y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			element->x, element->y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible,
			element->x, element->y);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass,
			element->x, element->y);
}

int	load_sprites(t_game *game)
{
	int		width;
	int		height;

	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "textures/grass.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->playerp = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	return (game->playerp && game->collectible && game->exit && game->grass && game->wall);
}

int	setup_mlx(t_game *game)
{
	t_element	*element;
	t_row		*row;
	int			i;
	int			j;

	i = 0;
	row = game->map->first;
	while (row)
	{
		element = row->first;
		j = 0;
		while (element)
		{
			put_image(element->value, game, element);
			element = element->next;
			j++;
		}
		i++;
		row = row->next;
	}
	mlx_key_hook(game->window, &key_press, game);
	mlx_hook(game->window, 17, 0, (void *)mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_loop(game->mlx);
	return (1);
}

void	open_window(t_game *game)
{
	int			x;
	int			y;
	t_element	*current;
	t_row		*row;

	x = 0;
	y = 0;
	current = game->map->first->first;
	while (current)
	{
		x += 64;
		current = current->next;
	}
	row = game->map->first;
	while (row)
	{
		y += 64;
		row = row->next;
	}
	if (!load_sprites(game))
		return ;
	game->window = mlx_new_window(game->mlx, x, y, "So_long");
}

t_game	*create_game(int fd, char **error)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (game);
	game->player->collectibles = 0;
	game->map = create_map(fd, game);
	close(fd);
	if (!game->map)
		return (game);
	game->map->game = game;
	*error = check(game->map, game->player);
	if (*error)
		return (game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (game);
	open_window(game);
	if (!game->window)
		return (game);
	setup_mlx(game);
	return (game);
}
