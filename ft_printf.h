/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:46:28 by mzomeno-          #+#    #+#             */
/*   Updated: 2020/01/10 13:26:36 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flags
{
	va_list		args;
	int			zero;
	int			minus;
	int			plus;
	int			width;
	int			precision;
	int			ret;
}				t_flags;

int				ft_printf(char *format, ...);
void			read_format(char *format, t_flags *s);
void			checking_flags(char *format, t_flags *s, int *it);
void			handle_types(char *format, int it, t_flags *s);
t_flags			*initialize(t_flags *s);
void			handle_flags(char	*format, t_flags *s, int *it);
void			handle_precision(char	*format, t_flags *s, int *it);
void			handle_width(char	*format, t_flags *s, int *it);
void			print_c(t_flags *s);
void			print_s(t_flags *s);
void			print_perc(t_flags *s);
void			print_i(t_flags *s);
void			i_minus(int i, t_flags *s);
void			i_no_minus(int i, t_flags *s);
void			print_u(t_flags *s);
void			u_minus(long int i, t_flags *s);
void			u_no_minus(long int i, t_flags *s);
void			print_x(t_flags *s, char *format, int it);
void			x_minus(long int i, t_flags *s, char *base);
void			x_no_minus(long int i, t_flags *s, char *base);
void			num_null(t_flags *s);
void			print_p(t_flags *s);
void			putchar_prntf(char c, t_flags *s);
void			putstr_prntf(char *str, t_flags *s);
int				ft_strlen(const char *str, int precision);
int				ft_strchr(const char *s, char c);
int				ft_intlen(long int d);
void			ft_putnbr(int nb, t_flags *s);
int				ft_intlen_hex(long int d);
void			ft_putnbr_hex(long int nb, t_flags *s, char *base);
void			ft_putlongnbr(long int nb, t_flags *s);

#endif
