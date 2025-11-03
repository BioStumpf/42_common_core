NAME := libftprintf.a
CC := cc
INC_DIR := includes
CFLAGS := -Wall -Wextra -Werror -c -I$(INC_DIR)
SRC_DIR := src/
OBJ_DIR := obj/
SRCS = numbers_utils.c parsing.c printf.c strings_utils.c
SRCS := $(addprefix $(SRC_DIR), $(SRCS))
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
