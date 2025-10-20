NAME := libft.a
BONUS_NAME := .bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror -c
SRCS := ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memmove.c ft_toupper.c ft_tolower.c ft_memcpy.c ft_memchr.c ft_strdup.c ft_bzero.c ft_itoa.c ft_isalpha.c ft_strrchr.c ft_strchr.c ft_split.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_strlcpy.c ft_striteri.c ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_putchar_fd.c ft_atoi.c ft_putstr_fd.c ft_substr.c ft_putendl_fd.c ft_calloc.c ft_putnbr_fd.c
 
OBJS := $(patsubst %.c, %.o, $(SRCS))
SRCS_BONUS := ft_lstsize_bonus.c ft_lstiter_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c

OBJS_BONUS := $(patsubst %.c, %.o, $(SRCS_BONUS)) 

all: $(NAME)

bonus: $(BONUS_NAME) 

$(NAME): $(OBJS)
	ar rcs $@ $?

$(BONUS_NAME): $(OBJS_BONUS) $(OBJS)
	ar rcs $(NAME) $?
	touch $(BONUS_NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf libft.a $(BONUS_NAME) 

re: fclean all

.PHONY: all bonus clean fclean re
