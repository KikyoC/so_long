/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:47 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/27 11:32:15 by togauthi         ###   ########.fr       */
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
	int			moved;

	moved = 0;
	old_pos = game->player->pos;
	if (keycode == XK_Escape)
		moved += mlx_loop_end(game->mlx);
	else if (keycode == XK_d)
		moved += right(game->player);
	else if (keycode == XK_w)
		moved += up(game->player);
	else if (keycode == XK_a)
		moved += left(game->player);
	else if (keycode == XK_s)
		moved += down(game->player);
	move_player(old_pos, game);
	game->player->movements += moved;
	if (moved)
		update_count(game);
	return (1);
}

int	game_loop(t_game *game)
{
	if (game->player->pos->exit && game->map->collectibles
		== game->player->collectibles)
		mlx_loop_end(game->mlx);
	if (game->fps >= 10000)
		game->fps = -1;
	if (game->bonus)
		game->fps++;
	animate_player(game);
	animate_collectibles(game);
	if (game->player->pos != game->exit)
		animate_portal(game);
	animate_patrol(game);
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*error;
	t_game		*game;

	if (argc < 2)
	{
		ft_printf("Error\nYou must provide a map path\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile not found\n");
		return (1);
	}
	error = NULL;
	game = create_game(fd, argv[1], &error, 1);
	if (error)
		ft_printf("Error\n%s\n", error);
	else if (game)
	{
		if (game->mlx && game->window)
			mlx_destroy_window(game->mlx, game->window);
		delete_game(game);
	}
}
