/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:20:16 by bhocsak           #+#    #+#             */
/*   Updated: 2024/05/30 17:48:57 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_pf(int c);
int		ft_putnbr_pf(int n);
int		ft_putstr_pf(char *str);
int		ft_putptr(void *ptr);
int		ft_putuint(unsigned int n);
int		ft_puthex(unsigned long n, const char base);

#endif
