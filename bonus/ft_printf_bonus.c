/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:48:33 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/10 12:44:18 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_printf(char *format, ...)
{
	t_flags		s;

	if (!format || !*format)
		return (0);
	initialize(&s);
	s.ret = 0;
	va_start(s.args, format);
	read_format(format, &s);
	va_end(s.args);
	return (s.ret);
}
