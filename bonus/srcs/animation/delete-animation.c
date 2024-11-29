/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:06 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/29 09:55:15 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

/* free_animation
*	Take the name, the animation and the number of frames as argument
*	Free images of an animation
*/
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
