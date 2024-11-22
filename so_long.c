/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:47 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 12:39:40 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_row(t_row *row)
{
	t_element	*current;

	current = row->first;
	while (current)
	{
		ft_printf("%c ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

void	print_map(t_map *map)
{
	t_row	*current;

	current = map->first;
	while (current)
	{
		print_row(current);
		current = current->next;
	}
}

int	key_press(int keycode, t_game *game)
{
	t_element	*old_pos;

	old_pos = game->player->pos;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (keycode == XK_d)
		right(game->player);
	else if (keycode == XK_w)
		up(game->player);
	else if (keycode == XK_a)
		left(game->player);
	else if (keycode == XK_s)
		down(game->player);
	move_player(old_pos, game);
	return (1);
}

int	game_loop(t_game *game)
{
	ft_printf("In game game collectibes: %d\nPlayer collected %d\n", game->map->collectibles, game->player->collectibles);
	if (game->player->pos->exit && game->map->collectibles == game->player->collectibles)
		mlx_loop_end(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*error;
	t_game		*game;

	if (argc < 2)
	{
		ft_printf("You must provide a map path\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File not found\n");
		return (1);
	}
	error = NULL;
	game = create_game(fd, &error);
	if (error)
		ft_printf("Error\n%s\n", error);
	else if (game)
	{
		if (game->mlx && game->window)
			mlx_destroy_window(game->mlx, game->window);
		delete_game(game);
	}
}
