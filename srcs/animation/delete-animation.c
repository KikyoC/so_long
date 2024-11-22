/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:06 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/22 14:14:58 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*free_animation(t_animation *animation)
{
	int		i;

	i = 0;
	while (animation->frames[i])
	{
		free(animation->frames[i]);
		i++;
	}
	free(animation->frames);
	free(animation);
	return (NULL);	
}