NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT_A = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I$(LIBFT_DIR)

SRCS = ft_puthex.c \
       ft_put_unsigned_nbr.c \
       ft_print_arg.c \
       ft_putnbr.c \
       ft_putvoid.c \
       ft_printf.c \
       ft_putstr.c \
       ft_utoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
