/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:52:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/11 11:25:16 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			handle_types(char *format, int it, t_flags *s)
{
	if (format[it] == 'c')
		print_c(s);
	else if (format[it] == 's')
		print_s(s);
	else if (format[it] == 'p')
		print_p(s);
	else if (format[it] == 'd' || format[it] == 'i')
		print_i(s);
	else if (format[it] == 'u')
		print_u(s);
	else if (format[it] == 'x' || format[it] == 'X')
		print_x(s, format, it);
	else
		print_perc(s);
}

void			checking_flags(char *format, t_flags *s, int *it)
{
	while (!ft_strchr("cspdiuxX%", format[*it]) && format[*it])
	{
		if (!ft_strchr("0123456789.-*+", format[*it]) && format[*it])
			return ;
		if (format[*it] == '*')
		{
			s->width = va_arg(s->args, int);
			if (s->width < 0)
			{
				s->width *= -1;
				s->minus = 1;
			}
			(*it)++;
		}
		handle_flags(format, s, it);
		handle_width(format, s, it);
		handle_precision(format, s, it);
	}
}

void			read_format(char *format, t_flags *s)
{
	int	it;

	it = -1;
	while (format[++it])
	{
		if (format[it] == '%')
		{
			it++;
			initialize(s);
			checking_flags(format, s, &it);
			if (!format[it])
				return ;
			handle_types(format, it, s);
			if (format[it + 1])
				it++;
			else
				return ;
		}
		if (format[it] != '%')
			putchar_prntf(format[it], s);
		else
			it--;
	}
}
