/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:40:28 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/10 12:45:14 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	print_c(t_flags *s)
{
	char	c;

	c = (char)va_arg(s->args, int);
	if (s->minus)
	{
		putchar_prntf(c, s);
		while (s->width > 1)
		{
			putchar_prntf(' ', s);
			s->width--;
		}
	}
	else
	{
		while (s->width > 1)
		{
			putchar_prntf(' ', s);
			s->width--;
		}
		putchar_prntf(c, s);
	}
}

void	print_s(t_flags *s)
{
	char	*str;
	int		precision;
	char	fill;

	str = va_arg(s->args, char *);
	if (str == NULL)
		str = "(null)";
	precision = s->precision;
	if (s->minus)
		putstr_prntf(str, s);
	if (s->zero && !s->minus)
		fill = '0';
	else
		fill = ' ';
	while (s->width > ft_strlen(str, precision))
	{
		putchar_prntf(fill, s);
		s->width--;
	}
	if (!s->minus)
		putstr_prntf(str, s);
}

void	print_perc(t_flags *s)
{
	char	fill;

	if (s->minus)
	{
		putchar_prntf('%', s);
		while (s->width > 1)
		{
			putchar_prntf(' ', s);
			s->width--;
		}
	}
	else
	{
		if (s->zero && s->precision == -1)
			fill = '0';
		else
			fill = ' ';
		while (s->width > 1)
		{
			putchar_prntf(fill, s);
			s->width--;
		}
		putchar_prntf('%', s);
	}
}
