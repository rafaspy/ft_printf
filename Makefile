# Nombres de librerías
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FTPRINTF = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente de ft_printf
FTPRINTF_SRCS = ft_printf.c ft_format.c
FTPRINTF_OBJS = $(FTPRINTF_SRCS:.c=.o)

# Includes
INCLUDES = -I$(LIBFT_DIR)

# Regla principal: compila ambas librerías
all: $(LIBFT) $(FTPRINTF)

# Compilar libft primero usando su Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar ft_printf y crear libftprintf.a
$(FTPRINTF): $(FTPRINTF_OBJS) $(LIBFT)
	ar rcs $(FTPRINTF) $(FTPRINTF_OBJS)

# Compilar .c a .o para ft_printf
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpiar objetos de ft_printf y libft
clean:
	rm -f $(FTPRINTF_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Limpiar todo (objetos y librerías)
fclean: clean
	rm -f $(FTPRINTF)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re
