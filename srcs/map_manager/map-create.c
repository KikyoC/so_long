/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 11:10:54 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	assign_element(t_element *element, t_row *row, char c, int *pos)
{
	element->prev = NULL;
	element->next = NULL;
	element->x = pos[0];
	element->y = pos[1];
	element->value = c;
	element->visited = 0;
	element->collectible = c == 'C';
	element->exit = c == 'E';
	element->row = row;
	if (c == 'P')
		element->row->map->game->player->pos = element;
}

t_row	*create_row(char *s, int *pos, t_map *map)
{
	t_row		*res;
	t_element	*element;
	int			i;

	res = ft_calloc(1, sizeof(t_row));
	i = -1;
	pos[0] = 0;
	if (!res)
		return (NULL);
	res->map = map;
	while (s[++i] && s[i] != '\n')
	{
		element = ft_calloc(1, sizeof(t_element));
		if (!element)
		{
			free_row(res);
			return (NULL);
		}
		assign_element(element, res, s[i], pos);
		put_row_end(res, element);
		pos[0] += 64;
	}
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

t_map	*create_map(int fd, t_game *game)
{
	char		*s;
	t_map		*res;
	t_row		*row;
	int			pos[2];

	s = get_next_line(fd);
	res = ft_calloc(1, sizeof(t_map));
	if (!res)
		return (NULL);
	res->game = game;
	pos[1] = 0;
	while (s)
	{
		row = create_row(s, pos, res);
		free(s);
		if (!row)
		{
			free(res);
			return (NULL);
		}
		put_map_end(res, row);
		s = get_next_line(fd);
		pos[1] += 64;
	}
	return (res);
}
