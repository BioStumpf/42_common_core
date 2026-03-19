# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

NAME := push_swap
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/
LIBFT_DIR := libft/

SRCS = main.c parsing.c stack_operations.c operation_printing_1.c operation_printing_2.c sorting3.c qsort.c sorting_helpers.c
LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS_OBJS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -c $< -o $@
CFLAGS_NAME = -Wall -Wextra -Werror -g -o $@ $(OBJS) $(LIBFT)
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       Make Binary          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	$(CC) $(CFLAGS_NAME)


$(LIBFT): FORCE
	@if $(MAKE) -q -sC $(LIBFT_DIR); then \
		:; \
	else \
		echo "$(GREEN)======================================$(RESET)"; \
		echo "$(BOLD)$(BLUE)       Make Libft          $(RESET)"; \
		echo "$(GREEN)======================================$(RESET)"; \
		$(MAKE) --no-print-directory -sC $(LIBFT_DIR); \
		echo "$(GREEN)======================================$(RESET)"; \
		echo "$(BOLD)$(BLUE)         DONE          $(RESET)"; \
		echo "$(GREEN)======================================$(RESET)"; \
		echo; \
	fi

FORCE:

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS_OBJS) $(DEP_FLAGS)

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

localclean:
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       LOCAL CLEANING         $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
	@echo 

clean: localclean
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       CLEANING         $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo 

fclean: localclean
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       FCLEANING       $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	rm -rf $(NAME)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo 

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re FORCE
