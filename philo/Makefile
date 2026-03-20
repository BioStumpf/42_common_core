# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

NAME := philo
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/

SRCS = main.c ft_atoi.c
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS_OBJS = -Wall -Wextra -Werror -g -c $< -o $@
CFLAGS_NAME = -Wall -Wextra -Werror -g -o $@ $(OBJS)
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       Make Binary          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	$(CC) $(CFLAGS_NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS_OBJS) $(DEP_FLAGS)

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean: 
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       CLEANING         $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
	@echo 

fclean: clean
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FCLEANING       $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	rm -rf $(NAME)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo 

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re 
