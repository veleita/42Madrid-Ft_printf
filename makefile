
NAME		=	libftprintf.a



CC			=	gcc

CFLAGS		+=	-Werror -Wall -Wextra

AR			=	ar -rcs



SRC			=	ft_printf.c \
				ft_printf_format.c \
				ft_printf_flags.c \
				types/ft_printf_alpha.c \
				types/ft_printf_i.c \
				types/ft_printf_hex.c \
				types/ft_printf_u.c \
				types/ft_printf_p.c \
				utils/ft_printf_utils_char.c \
				utils/ft_printf_utils_int.c

SRC_BONUS	=	bonus/ft_printf_bonus.c \
				bonus/ft_printf_format_bonus.c \
				bonus/ft_printf_flags_bonus.c \
				bonus/types/ft_printf_alpha_bonus.c \
				bonus/types/ft_printf_i_bonus.c \
				bonus/types/ft_printf_hex_bonus.c \
				bonus/types/ft_printf_u_bonus.c \
				bonus/types/ft_printf_p_bonus.c \
				bonus/utils/ft_printf_utils_char_bonus.c \
				bonus/utils/ft_printf_utils_int_bonus.c


OBJS		=	$(SRC:%.c=%.o)

OBJS_BONUS	=	$(SRC_BONUS:%.c=%.o)


all:		$(NAME)

$(NAME): $(OBJS) ft_printf.h
			$(AR) $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I.


bonus: $(OBJS_BONUS) $(OBJS) ft_printf.h
			$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
#main:
#			$(CC) $(CFLAGS) -o $(NAME) $(SRC) main.c && ./$(NAME)

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
			rm -rf $(NAME)

re: fclean all


.PHONY: clean fclean all re
