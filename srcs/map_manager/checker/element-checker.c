/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element-checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:18:55 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:40:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	full(t_row *row)
{
	t_element	*current;

	current = row->first;
	while (current)
	{
		if (current->value != '1')
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_border(t_map *map)
{
	t_row		*row;

	row = map->first;
	if (!(full(map->first) && full(last_in_map(map))))
		return (0);
	row = row->next;
	while (row->next)
	{
		if (row->first->value == '0' || last_in_row(row)->value == '0')
			return (0);
		row = row->next;
	}
	return (1);
}

int	is_rect(t_map *map)
{
	int		len;
	t_row	*current;

	len = row_len(map->first);
	current = map->first;
	while (current)
	{
		if (row_len(current) != len)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_element(int *start, int *end, int *collectibles, t_element *element)
{
	if (element->value == 'P')
		*start += 1;
	else if (element->value == 'E')
		*end += 1;
	else if (element->value == 'C')
		*collectibles += 1;
	else if (element->value != '1' && element->value != '0')
		return (0);
	return (1);
}

int	check_elements(t_map *map)
{
	t_row		*row;
	t_element	*element;
	int			start;
	int			end;
	int			collectibles;

	start = 0;
	end = 0;
	collectibles = 0;
	row = map->first;
	while (row)
	{
		element = row->first;
		while (element)
		{
			if (!check_element(&start, &end, &collectibles, element))
				return (0);
			element = element->next;
		}
		row = row->next;
	}
	return (start == 1 && end == 1 && collectibles >= 1);
}
