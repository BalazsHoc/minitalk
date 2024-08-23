/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:38:03 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/07 15:14:53 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	uintlen(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*uitoa(unsigned int n)
{
	char			*result;
	unsigned int	digits;
	unsigned int	num;

	num = n;
	digits = uintlen(num);
	result = (void *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (0);
	*(result + digits) = '\0';
	while (digits--)
	{
		*(result + digits) = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

int	ft_putuint(unsigned int n)
{
	unsigned int	printed;
	char			*unum;

	printed = 0;
	unum = uitoa(n);
	printed += ft_putstr_pf(unum);
	free(unum);
	return (printed);
}
