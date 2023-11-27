/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 03:02:16 by elchakir          #+#    #+#             */
/*   Updated: 2023/10/03 21:27:03 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, char check, int *len)
{
	unsigned int	bl;
	char			*base;

	bl = 16;
	if (check == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (n < bl)
	{
		ft_putchar(base[n % bl], len);
	}
	else
	{
		ft_putnbr_base(n / bl, check, len);
		ft_putnbr_base(n % bl, check, len);
	}
}
