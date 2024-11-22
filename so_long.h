/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:40:37 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 11:46:47 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "X11/X.h"

typedef struct s_element
{
	struct s_element	*next;
	struct s_element	*prev;
	struct s_row		*row;
	char				value;
	int					visited;
	int					exit;
	int					collectible;
	int					x;
	int					y;

}	t_element;

typedef struct s_row
{
	struct s_row		*next;
	struct s_row		*prev;
	struct s_map		*map;
	struct s_element	*first;

}	t_row;

typedef struct s_map
{
	int					collectibles;
	struct s_game		*game;
	struct s_row		*first;
}	t_map;

typedef struct s_player
{
	int					collectibles;
	struct s_element	*pos;	
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_map		*map;
	void		*coin;
	void		*collectible;
	void		*exit;
	void		*grass;
	void		*playerp;
	void		*wall;
}	t_game;

void		free_map(t_map *map);
void		free_row(t_row *row);
void		put_map_end(t_map *map, t_row *element);
void		put_row_end(t_row *row, t_element *element);
t_map		*create_map(int fd, t_game *game);
char		*get_next_line(int fd);
t_element	*last_in_row(t_row *row);
t_row		*last_in_map(t_map *map);
char		*check(t_map *map, t_player *player);
int			row_len(t_row *row);
int			left(t_player *player);
int			right(t_player *player);
int			up(t_player *player);
int			down(t_player *player);
int			is_solvable(t_map *map, t_player *player);
void		refresh_collectibles(t_map *map);
int			check_up(t_player *player);
int			check_down(t_player *player);
int			check_left(t_player *player);
int			check_right(t_player *player);
void		solve(t_player *player);
t_game		*create_game(int fd, char **error);
int			game_loop(t_game *game);
int			key_press(int keycode, t_game *game);
int			delete_game(t_game *game);
void		move_player(t_element *old_pos, t_game *game);
void		print_map(t_map *map);
void		move_player(t_element *old_pos, t_game *game);
#endif