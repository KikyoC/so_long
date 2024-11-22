/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move-check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:57 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 11:41:17 by togauthi         ###   ########.fr       */
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
			solve(player);
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
			solve(player);
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
			solve(player);
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
			solve(player);
			left(player);
		}
	}
	return (0);
}
