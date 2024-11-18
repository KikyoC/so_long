/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:07 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:53 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_row	*create_row(char *s)
{
	t_row		*res;
	t_element	*element;
	int			i;

	res = ft_calloc(1, sizeof(t_row));
	i = 0;
	if (!res)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		element = ft_calloc(1, sizeof(t_element));
		if (!element)
		{
			free_row(res);
			return (NULL);
		}
		element->prev = NULL;
		element->next = NULL;
		element->value = s[i];
		put_row_end(res, element);
		i++;
	}
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

t_map	*create_map(int fd)
{
	char		*s;
	t_map		*res;
	t_row		*row;
	int			i;

	s = get_next_line(fd);
	res = ft_calloc(1, sizeof(t_map));
	if (!res)
		return (NULL);
	while (s)
	{
		i = 0;
		row = create_row(s);
		if (!row)
		{
			free(res);
			free(s);
			return (NULL);
		}
		put_map_end(res, row);
		free(s);
		s = get_next_line(fd);
	}
	return (res);
}
