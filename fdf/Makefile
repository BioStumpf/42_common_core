NAME := fdf
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/
LIBFT_DIR := libft/
MINI_DIR := minilibx-linux/

SRCS = $(wildcard *.c)
LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS_OBJS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MINI_DIR) -c $< -o $@
CFLAGS_NAME = -Wall -Wextra -Werror -g -o $@ $(OBJS) $(LIBFT) -lm -L$(MINI_DIR) -lmlx_Linux -lXext -lX11
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@echo "======================================"
	@echo "       Building FDF binary           "
	@echo "======================================"
	$(CC) $(CFLAGS_NAME)
	@echo "======================================"
	@echo "       FDF binary DONE          "
	@echo "======================================"

$(LIBFT):
	@echo "======================================"
	@echo "       Building Libft           "
	@echo "======================================"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "======================================"
	@echo "       Libft DONE          "
	@echo "======================================"

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "======================================"
	@echo "       Building FDF OBJS           "
	@echo "======================================"
	$(CC) $(CFLAGS_OBJS) $(DEP_FLAGS)
	@echo "======================================"
	@echo "       FDF OBJS DONE          "
	@echo "======================================"

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

localclean:
	@echo "======================================"
	@echo "       CLEAN FDF          "
	@echo "======================================"
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
	@echo "======================================"
	@echo "       DONE          "
	@echo "======================================"

clean: localclean
	@echo "======================================"
	@echo "       CLEAN LIBFT          "
	@echo "======================================"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "======================================"
	@echo "       DONE         "
	@echo "======================================"

fclean: localclean
	@echo "======================================"
	@echo "       FCLEAN FDF        "
	@echo "======================================"
	rm -rf $(NAME)
	@echo "======================================"
	@echo "       DONE       "
	@echo "======================================"
	@echo "======================================"
	@echo "       FCLEAN libft        "
	@echo "======================================"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "======================================"
	@echo "       DONE        "
	@echo "======================================"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
