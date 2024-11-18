/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:27:44 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:23:42 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*left
	Try to turn on the left.
	If it fails it will return 0 else 1
*/

int	left(t_player *player)
{
	if (player->pos->prev->value == '1')
		return (0);
	player->pos->value = '0';
	player->pos = player->pos->prev;
	player->pos->value = 'P';
	return (1);
}

/*right
	Try to turn on the right.
	If it fails it will return 0 else 1
*/

int	right(t_player *player)
{
	if (player->pos->next->value == '1')
		return (0);
	player->pos->value = '0';
	player->pos = player->pos->next;
	player->pos->value = 'P';
	return (1);
}

/*up
	Try to go up.
	If it fails it will return 0 else 1
*/

int	up(t_player *player)
{
	int			element_rank;
	t_element	*current;

	element_rank = 0;
	if (!player->pos->row)
		return (0);
	current = player->pos->row->first;
	while (current != player->pos)
	{
		element_rank++;
		current = current->next;
	}
	current = player->pos->row->prev->first;
	while (element_rank > 0)
	{
		current = current->next;
		element_rank--;
	}
	if (current->value == '1')
		return (0);
	current->value = 'P';
	player->pos->value = '0';
	player->pos = current;
	return (1);
}

/*down
	Try to go down.
	If it fails it will return 0 else 1
*/

int	down(t_player *player)
{
	int			element_rank;
	t_element	*current;

	element_rank = 0;
	if (!player->pos->row)
		return (0);
	current = player->pos->row->first;
	while (current != player->pos)
	{
		element_rank++;
		current = current->next;
	}
	current = player->pos->row->next->first;
	while (element_rank > 0)
	{
		current = current->next;
		element_rank--;
	}
	if (current->value == '1')
		return (0);
	current->value = 'P';
	player->pos->value = '0';
	player->pos = current;
	return (1);
}
