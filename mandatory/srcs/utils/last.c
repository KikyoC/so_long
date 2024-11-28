/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:26:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 10:23:19 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_longm.h>

t_element	*last_in_row(t_row *row)
{
	t_element	*current;

	current = row->first;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

t_row	*last_in_map(t_map *map)
{
	t_row	*current;

	current = map->first;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
