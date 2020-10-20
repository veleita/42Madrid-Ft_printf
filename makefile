
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

OBJS		=	$(SRC:%.c=%.o)


all:		$(NAME)

$(NAME): $(OBJS) ft_printf.h
			$(AR) $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I.


#main:
#			$(CC) $(CFLAGS) -o $(NAME) $(SRC) main.c && ./$(NAME)

clean:
			rm -rf $(OBJS)

fclean: clean
			rm -rf $(NAME)

re: fclean all


.PHONY: clean fclean all re
