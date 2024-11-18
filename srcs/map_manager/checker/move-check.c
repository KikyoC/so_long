/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move-check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:57 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	check_up(t_player *player)
{
	if (up(player))
	{
		if (player->pos->visited)
			down(player);
		else
		{
			player->pos->visited = 1;
			if (solve(player))
				return (1);
			else
				down(player);
		}
	}
	return (0);
}

int	check_down(t_player *player)
{
	if (down(player))
	{
		if (player->pos->visited)
			up(player);
		else
		{
			player->pos->visited = 1;
			if (solve(player))
				return (1);
			else
				up(player);
		}
	}
	return (0);
}

int	check_left(t_player *player)
{
	if (left(player))
	{
		if (player->pos->visited)
			right(player);
		else
		{
			player->pos->visited = 1;
			if (solve(player))
				return (1);
			else
				right(player);
		}
	}
	return (0);
}

int	check_right(t_player *player)
{
	if (right(player))
	{
		if (player->pos->visited)
			left(player);
		else
		{
			player->pos->visited = 1;
			if (solve(player))
				return (1);
			else
				left(player);
		}
	}
	return (0);
}
