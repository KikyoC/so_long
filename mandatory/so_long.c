/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:47 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:21:30 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* key_press:
	Takes keycode and general game as argument
	Move the player if keycode is w,a,s or d and close if escape
*/
int	key_press(int keycode, t_game *game)
{
	t_element	*old_pos;
	int			moved;

	moved = 0;
	old_pos = game->player->pos;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (keycode == XK_d)
		moved += right(game->player);
	else if (keycode == XK_w)
		moved += up(game->player);
	else if (keycode == XK_a)
		moved += left(game->player);
	else if (keycode == XK_s)
		moved += down(game->player);
	if (moved)
		move_player(old_pos, game);
	game->player->movements += moved;
	if (moved)
		ft_printf("%d\n", game->player->movements);
	return (1);
}

/* game_loop:
	Takes the game as argument
	Check each loop if player has finished the game
*/
int	game_loop(t_game *game)
{
	if (game->player->pos->exit && game->map->collectibles
		== game->player->collectibles)
		mlx_loop_end(game->mlx);
	return (1);
}
/* main:
	Main function that makes basic checks and launch the game
*/
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
	game = create_game(fd, argv[1], &error);
	if (error)
		ft_printf("Error\n%s\n", error);
	if (game)
	{
		if (game->mlx && game->window)
			mlx_destroy_window(game->mlx, game->window);
		delete_game(game);
	}
}
