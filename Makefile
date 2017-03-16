# Name of the library
NAME = libft.a

# Compiling flags
FLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# all rule
all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[INFO] Library [$(NAME)] created!"

# clean rule
clean:
	@rm -f $(OBJ)
	@echo "[INFO] Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Library [$(NAME)] removed!"

# re rule
re:	fclean all

# phony
.PHONY: all, clean, fclean, re
