/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:54:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/25 11:25:35 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putunbr(unsigned int nb)
{
	if (nb >= 10)
		return (ft_putunbr(nb / 10) + ft_putunbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
	return (0);
}
