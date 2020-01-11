/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:56:07 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/10 12:10:13 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	putchar_prntf(char c, t_flags *s)
{
	write(1, &c, 1);
	s->ret++;
}

void	putstr_prntf(char *str, t_flags *s)
{
	int it;

	it = -1;
	while (str[++it] && s->precision)
	{
		putchar_prntf(str[it], s);
		s->precision--;
	}
	s->precision = -1;
}

int		ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (c == 0)
		return (1);
	else
		return (0);
}

int		ft_strlen(const char *str, int precision)
{
	int cont;

	cont = 0;
	while (*(str++) != '\0' && (precision--) != 0)
		cont++;
	return (cont);
}
