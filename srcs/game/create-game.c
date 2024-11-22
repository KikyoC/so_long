/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create-game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:07:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/21 17:56:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void	put_image(char c, t_game *game, t_element *element)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, element->x, element->y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->playerp, element->x, element->y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, element->x, element->y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible, element->x, element->y);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass, element->x, element->y);
}

void	load_sprites(t_game *game)
{
	int		width;
	int		height;

	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "textures/grass.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	game->playerp = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
}

void	move_player(t_element *old_pos, t_game *game)
{
	char	*path;
	int		width;
	int		height;
	void	*img;
	
	if (old_pos->value == '1')
		path = "textures/wall.xpm";
	else if (old_pos->value == 'P')
		path = "textures/player.xpm";
	else if (old_pos->value == 'E')
		path = "textures/exit.xpm";
	else if (old_pos->value == 'C')
		path = "textures/collectible.xpm";
	else
		path = "textures/grass.xpm";
	width = 64;
	height = 64;
	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	mlx_put_image_to_window(game->mlx, game->window, img, old_pos->x, old_pos->y);
	mlx_destroy_image(game->mlx, img);
	img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->window, img, game->player->pos->x, game->player->pos->y);
	mlx_destroy_image(game->mlx, img);
}

int	aff_img_everywhere(t_game *game)
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
	load_sprites(game);
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
		return (NULL);
	game->map = create_map(fd, game->player);
	close(fd);
	*error = check(game->map, game->player);
	if (*error)
		return (NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (NULL);
	open_window(game);
	if (!game->window)
		return (NULL);
	aff_img_everywhere(game);
	mlx_key_hook(game->window, &key_press, game);
	mlx_hook(game->window, 17, 0, (void *)mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_loop(game->mlx);
	return (game);
}
