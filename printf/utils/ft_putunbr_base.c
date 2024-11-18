/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:12:10 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/30 13:23:49 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putunbr_base(unsigned int nb, char *base)
{
	if (nb >= (unsigned int)ft_printf_strlen(base))
		return (ft_putunbr_base(nb / ft_printf_strlen(base), base)
			+ ft_putunbr_base(nb % ft_printf_strlen(base), base));
	else
		return (write(1, &base[nb], 1));
	return (0);
}
