NAME := libft.a
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/

CFLAGS = -Wall -Wextra -Werror -g -c $< -o $@
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

SRCS := ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memmove.c ft_toupper.c ft_tolower.c ft_memcpy.c ft_memchr.c ft_strdup.c ft_bzero.c ft_itoa.c ft_isalpha.c ft_strrchr.c ft_strchr.c ft_split.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_strlcpy.c ft_striteri.c ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_putchar_fd.c ft_atoi.c ft_putstr_fd.c ft_substr.c ft_putendl_fd.c ft_calloc.c ft_putnbr_fd.c printf.c printf_numbers_utils.c printf_parsing.c printf_strings_utils.c get_next_line.c get_next_line_utils.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstnode_new.c ft_lstprint.c ft_iswhitespace.c ft_atoi_multi.c ft_counting.c ft_atoi_hex_multi.c
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 
 
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
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
