NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FTPRINTF_SRCS = ft_printf.c \
	ft_format.c \
	ft_utils.c

FTPRINTF_OBJS = $(FTPRINTF_SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(FTPRINTF_OBJS) $(LIBFT)
	ar rcs $(NAME) $(FTPRINTF_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(FTPRINTF_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
