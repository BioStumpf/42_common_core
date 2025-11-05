NAME := libftprintf.a
CC := cc

INC_DIR := includes
DEP_DIR := dep/
SRC_DIR := src/
OBJ_DIR := obj/

SRCS = numbers_utils.c parsing.c printf.c strings_utils.c
SRCS := $(addprefix $(SRC_DIR), $(SRCS))
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst $(SRC_DIR)%.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -c $< -o $@
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS)

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(DEP_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
