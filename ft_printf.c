/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:17:40 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/27 23:36:24 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	more_flags(va_list args, const char flag, int *len)
{
	char	*str;

	if (flag == 'u')
	{
		ft_putnbr_u(va_arg(args, unsigned int), len);
	}
	else if (flag == 'c')
	{
		ft_putchar(va_arg(args, int), len);
	}
	else if (flag == 's')
	{
		str = va_arg(args, char *);
		if (str != NULL)
		{
			ft_putstr(str, len);
		}
		else
		{
			ft_putstr("(null)", len);
		}
	}
	else
		ft_putchar(flag, len);
}

void	flags(va_list args, const char flag, int *len)
{
	void	*ptr;

	if (flag == '%')
		ft_putchar(flag, len);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (flag == 'X' || flag == 'x')
		ft_putnbr_base(va_arg(args, int), flag, len);
	else if (flag == 'p')
	{
		ptr = va_arg(args, void *);
		ft_putadd(ptr, len);
	}
	else
		more_flags(args, flag, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags(args, *format, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
