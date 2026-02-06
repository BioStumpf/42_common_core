# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

NAME := fdf
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/
LIBFT_DIR := libft/

SRCS = $(wildcard *.c)
LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS_OBJS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -c $< -o $@
CFLAGS_NAME = -Wall -Wextra -Werror -g -o $@ $(OBJS) $(LIBFT) -lm -lXext -lX11 -lmlx
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d


all: $(NAME)

bonus : all

$(NAME): $(LIBFT) $(OBJS) 
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FDF OBJS DONE          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo
	$(CC) $(CFLAGS_NAME)
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FDF binary DONE          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"

$(LIBFT):
	$(MAKE) --no-print-directory -sC $(LIBFT_DIR)
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       Libft DONE          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo 

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS_OBJS) $(DEP_FLAGS)

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

localclean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FDF CLEANING DONE          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo 

clean: localclean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       LIBFT CLEANING DONE         $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo 

fclean: localclean
	rm -rf $(NAME)
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FDF FCLEANING DONE       $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo 
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       LIBFT FCLEANING DONE        $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo 

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
