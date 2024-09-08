/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:29:59 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/30 17:47:53 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex(unsigned long n, const char base)
{
	int	printed;

	printed = 0;
	if (n >= 16)
	{
		printed += hex(n / 16, base);
		printed += hex(n % 16, base);
	}
	else
	{
		if (n <= 9)
			printed += ft_putchar_pf(n + '0');
		else
		{
			n -= 10;
			if (base == 'x')
				printed += ft_putchar_pf(n + 'a');
			else
				printed += ft_putchar_pf(n + 'A');
		}
	}
	return (printed);
}

int	ft_puthex(unsigned long n, const char base)
{
	int	printed;

	printed = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		printed += hex(n, base);
	return (printed);
}
/*
int	main()
{
	unsigned long long num = ULONG_MAX;
	ft_puthex(num, 'x');
	return (0);
}*/
