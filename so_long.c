/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:47 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/19 11:17:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

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

int	main(int argc, char **argv)
{
	int			fd;
	char		*error;
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*mlx_win;

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
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (1);
	map = create_map(fd, player);
	print_map(map);
	error = check(map, player);
	if (error)
		ft_printf("Error\n%s\n", error);
	else
		ft_printf("Map loaded\n");

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
	(void)mlx_win;
	mlx_loop(mlx);
	free_map(map);
	free(player);
	close(fd);
}
