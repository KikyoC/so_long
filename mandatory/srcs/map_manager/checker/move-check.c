/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move-check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:57 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 11:33:44 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* check_up:
*	Take the player as parameter
*	Check if player can go up and if that pos isn't visited
*	If it's visited the player go back
*/
void	check_up(t_player *player)
{
	if (up(player))
	{
		if (player->pos->visited)
			down(player);
		else
		{
			player->pos->visited = 1;
			solve(player);
			down(player);
		}
	}
}

/* check_down:
*	Take the player as parameter
*	Check if player can go down and if that pos isn't visited
*	If it's visited the player go back
*/
void	check_down(t_player *player)
{
	if (down(player))
	{
		if (player->pos->visited)
			up(player);
		else
		{
			player->pos->visited = 1;
			solve(player);
			up(player);
		}
	}
}

/* check_left:
*	Take the player as parameter
*	Check if player can go left and if that pos isn't visited
*	If it's visited the player go back
*/
void	check_left(t_player *player)
{
	if (left(player))
	{
		if (player->pos->visited)
			right(player);
		else
		{
			player->pos->visited = 1;
			solve(player);
			right(player);
		}
	}
}

/* check_right:
*	Take the player as parameter
*	Check if player can go right and if that pos isn't visited
*	If it's visited the player go back
*/
void	check_right(t_player *player)
{
	if (right(player))
	{
		if (player->pos->visited)
			left(player);
		else
		{
			player->pos->visited = 1;
			solve(player);
			left(player);
		}
	}
}
