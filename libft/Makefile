NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = ft_atoi.c ft_itoa.c ft_strlcat.c  ft_substr.c ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c  ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_putendl_fd.c

OBJECT_FILES = $(SRCS_FILES:.c=.o)

BONUS_SRCS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

BONUS_OBJECT_FILES = $(BONUS_SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar rcs $(NAME) $(OBJECT_FILES)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

bonus: $(OBJECT_FILES) $(BONUS_OBJECT_FILES)
	ar rcs $(NAME) $(BONUS_OBJECT_FILES) $(OBJECT_FILES)

clean:
	rm -f $(OBJECT_FILES) $(BONUS_OBJECT_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
