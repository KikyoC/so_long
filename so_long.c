/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:47 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 10:37:11 by togauthi         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

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
	map = create_map(fd);
	print_map(map);
	ft_printf("%d\n", check(map));
	free_map(map);
	close(fd);
}