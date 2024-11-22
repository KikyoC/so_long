/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/21 17:44:18 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	assign_element(t_element *element, t_player *player, char c, int x, int y)
{
	element->prev = NULL;
	element->next = NULL;
	element->x = x;
	element->y = y;
	element->value = c;
	element->visited = 0;
	element->collectible = c == 'C';
	element->exit = c == 'E';
	if (c == 'P')
		player->pos = element;
}

t_row	*create_row(char *s, t_player *player, int y)
{
	t_row		*res;
	t_element	*element;
	int			i;
	int			x;

	res = ft_calloc(1, sizeof(t_row));
	i = -1;
	x = 0;
	if (!res)
		return (NULL);
	while (s[++i] && s[i] != '\n')
	{
		element = ft_calloc(1, sizeof(t_element));
		if (!element)
		{
			free_row(res);
			return (NULL);
		}
		assign_element(element, player, s[i], x, y);
		put_row_end(res, element);
		x += 64;
	}
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

t_map	*create_map(int fd, t_player *player)
{
	char		*s;
	t_map		*res;
	t_row		*row;
	int			y;

	s = get_next_line(fd);
	res = ft_calloc(1, sizeof(t_map));
	if (!res)
		return (NULL);
	y = 0;
	while (s)
	{
		row = create_row(s, player, y);
		if (!row)
		{
			free(res);
			free(s);
			return (NULL);
		}
		put_map_end(res, row);
		free(s);
		s = get_next_line(fd);
		y += 64;
	}
	return (res);
}
