/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:09:08 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/10 12:10:26 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_intlen(long int d)
{
	int		count;

	count = 0;
	if (d == 0)
		count = 1;
	if (d < 0)
		d = -d;
	while (d > 0)
	{
		d /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int nb, t_flags *s)
{
	char			digit;

	if (nb == -2147483648)
	{
		putstr_prntf("2147483648", s);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
	{
		digit = nb + '0';
		putchar_prntf(digit, s);
	}
	else
	{
		ft_putnbr(nb / 10, s);
		digit = nb % 10 + '0';
		putchar_prntf(digit, s);
	}
}

int		ft_intlen_hex(long int d)
{
	int		count;

	count = 0;
	if (d == 0)
		count = 1;
	while (d > 0)
	{
		d /= 16;
		count++;
	}
	return (count);
}

void	ft_putnbr_hex(long int nb, t_flags *s, char *base)
{
	char			digit;
	int				rem;

	if (nb < 16)
	{
		digit = base[nb];
		putchar_prntf(digit, s);
	}
	else
	{
		ft_putnbr_hex(nb / 16, s, base);
		rem = nb % 16;
		digit = base[rem];
		putchar_prntf(digit, s);
	}
}

void	ft_putlongnbr(long int nb, t_flags *s)
{
	char	digit;

	if (nb < 10)
	{
		digit = nb + '0';
		putchar_prntf(digit, s);
	}
	else
	{
		ft_putlongnbr(nb / 10, s);
		digit = nb % 10 + '0';
		putchar_prntf(digit, s);
	}
}
