/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/30 13:23:17 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putullnbr_base(unsigned long long nb, char *base)
{
	if (nb >= (unsigned long long)ft_printf_strlen(base))
	{
		return (ft_putullnbr_base(nb / ft_printf_strlen(base), base)
			+ ft_putullnbr_base(nb % ft_printf_strlen(base), base));
	}
	else
	{
		write(1, &base[nb], 1);
		return (1);
	}
	return (0);
}

int	ft_print_mem(void *p)
{
	if ((unsigned long long)p == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x")
		+ ft_putullnbr_base((unsigned long long)p, "0123456789abcdef"));
}
