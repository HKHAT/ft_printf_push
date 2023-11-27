/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:24:31 by elchakir          #+#    #+#             */
/*   Updated: 2023/10/06 10:25:51 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	while (str && *str)
	{
		ft_putchar(*str, len);
		str++;
	}
}
