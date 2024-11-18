/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:45:41 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/25 10:45:59 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_string(va_list args, const char *format)
{
	if (format[1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[1] == 'i' || format[1] == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (format[1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[1] == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format[1] == 'x')
		return (ft_putunbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (format[1] == 'X')
		return (ft_putunbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (format[1] == 'p')
		return (ft_print_mem(va_arg(args, void *)));
	else if (format[1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	can_be_formatted(char c)
{
	return (c == 's' || c == 'i' || c == 'c' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == '%' || c == 'd');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%' && can_be_formatted(format[i + 1]))
			len += format_string(args, format + i++);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
