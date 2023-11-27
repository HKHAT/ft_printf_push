/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 03:09:52 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/27 23:24:13 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_add(unsigned long int n, char x, int *len)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < base_len)
		ft_putchar(base[n % base_len], len);
	else
	{
		ft_putnbr_add(n / base_len, x, len);
		ft_putnbr_add(n % base_len, x, len);
	}
}

void	ft_putadd(void *add, int *len)
{
	unsigned long int	p;

	p = (unsigned long int)add;
	if (p == 0)
	{
		ft_putstr("0x0", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_putnbr_add(p, 'x', len);
}
