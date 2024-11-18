/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:48:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/15 13:22:44 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_args(int argc, char **argv)
{
	int		i;
	char	*c;

	if (argc < 2)
		return (1);
	if (!argv[1][0])
		return (0);
	i = 1;
	while (i < argc)
	{
		c = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(c, argv[i], ft_strlen(argv[i])))
		{
			free(c);
			return (0);
		}
		free(c);
		i++;
	}
	return (1);
}
