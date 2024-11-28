/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:06 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 13:49:38 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	*free_animation(t_game *game, t_animation *animation, int frames)
{
	int		i;

	i = 0;
	if (!animation)
		return (NULL);
	while (i <= frames)
	{
		if (animation->frames[i])
			mlx_destroy_image(game->mlx, animation->frames[i]);
		i++;
	}
	free(animation->frames);
	free(animation);
	return (NULL);
}
