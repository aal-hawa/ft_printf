NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_print_chr.c ft_print_int.c ft_print_str.c ft_printf.c ft_print_pointer.c ft_print_u.c ft_print_hex_lowercase.c ft_print_hex_uppercase.c 

OBGS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBGS)
	ar rcs $(NAME) $(OBGS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBGS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 