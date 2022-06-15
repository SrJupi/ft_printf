NAME = libftprintf.a

HEADER = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = ft_printf.c ft_putchar.c ft_putstr.c print_hexa.c print_uint.c

OBJ = $(SRC_C:.c=.o)

all: 	$(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@ar -rcs $(NAME) $(OBJ) $(HEADER)
	@echo "Mandatory part compiled"

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@echo ".a cleaned"
	

clean:
	@rm -f $(OBJ_BONUS) $(OBJ)
	@echo ".o cleaned"
	
.PHONY: fclean, all, clean, re