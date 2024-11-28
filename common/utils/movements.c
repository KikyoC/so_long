/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:27:44 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:22:30 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* left:
*	Take the player as parameter
*	Try to go left. If he can the function return 1
*	Check if it's a collectible and add it to count
*/
int	left(t_player *player)
{
	if (!player->pos->prev || player->pos->prev->value == '1')
		return (0);
	player->collectibles += player->pos->prev->value == 'C';
	player->pos->value = '0';
	player->pos = player->pos->prev;
	player->pos->value = 'P';
	return (1);
}

/* right:
*	Take the player as parameter
*	Try to go right. If he can the function return 1
*	Check if it's a collectible and add it to count
*/
int	right(t_player *player)
{
	if (!player->pos->next || player->pos->next->value == '1')
		return (0);
	player->collectibles += player->pos->next->value == 'C';
	player->pos->value = '0';
	player->pos = player->pos->next;
	player->pos->value = 'P';
	return (1);
}

/* up:
*	Take the player as parameter
*	Try to go up. If he can the function return 1
*	Check if it's a collectible and add it to count
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
	player->collectibles += current->value == 'C';
	current->value = 'P';
	player->pos->value = '0';
	player->pos = current;
	return (1);
}

/* down:
*	Take the player as parameter
*	Try to go down. If he can the function return 1
*	Check if it's a collectible and add it to count
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
	player->collectibles += current->value == 'C';
	current->value = 'P';
	player->pos->value = '0';
	player->pos = current;
	return (1);
}
