/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:52:14 by bhocsak           #+#    #+#             */
/*   Updated: 2024/06/12 17:37:18 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int		count;
	long	nmr;

	count = 1;
	nmr = n;
	if (nmr < 0)
	{
		count += ft_putchar_pf('-');
		nmr *= -1;
	}
	if (nmr >= 10)
		count += ft_putnbr_pf(nmr / 10);
	ft_putchar_pf(nmr % 10 + '0');
	return (count);
}
