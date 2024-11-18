/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:23:06 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/30 13:24:25 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_base(int nb, char *base)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		return (1 + ft_putnbr_base(-(nb / ft_printf_strlen(base)), base)
			+ ft_putnbr_base(-(nb % ft_printf_strlen(base)), base));
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		return (1 + ft_putnbr_base(-nb, base));
	}
	if (nb >= ft_printf_strlen(base))
	{
		return (ft_putnbr_base(nb / ft_printf_strlen(base), base)
			+ ft_putnbr_base(nb % ft_printf_strlen(base), base));
	}
	else
		return (write(1, &base[nb], 1));
	return (0);
}
