/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:36 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 14:15:27 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void	**create_animation(t_game *game, void *img, int x_start, int frames)
{
	void	**res;
	int		i;

	res = ft_calloc(frames + 1, sizeof(void *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < frames)
	{
		res[i] = mlx_new_image(game->mlx, 64, 64);
		if (!res[i])
			return (free_animation(res));
			
		i++;
	}
}


void	aff_part(t_game *game, int part)
{
	
}



void	animate_player(t_game *game)
{
	if (game->fps == 0)
	{
		
	}
}