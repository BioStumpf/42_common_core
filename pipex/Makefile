# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

NAME := pipex
CC := cc

DEP_DIR := dep/
OBJ_DIR := obj/
LIBFT_DIR := libft/

SRCS = cleanup.c handle_args.c 
SRCS_MANDATORY = main.c child_utils.c
OBJS_MANDATORY = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS_MANDATORY))
SRCS_BONUS = main_bonus.c heredoc_bonus.c child_utils_bonus.c
OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

ifeq ($(BONUS), 1)
	SRCS += $(SRCS_BONUS)
else
	SRCS += $(SRCS_MANDATORY)
endif

LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.c, $(DEP_DIR)%.d, $(SRCS)) 

CFLAGS_OBJS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -c $< -o $@
CFLAGS_NAME = -Wall -Wextra -Werror -o $@ $(OBJS) $(LIBFT)
DEP_FLAGS = -MMD -MP -MT $@ -MF $(DEP_DIR)$*.d

ifeq ($(dbg), 1)
	CFLAGS_OBJS += -g
endif

all: $(NAME)

bonus:
	@$(MAKE) --no-print-directory BONUS=1

$(NAME): $(LIBFT) $(OBJS) 
	@if [ "$(BONUS)" = 1 ]; then rm -f $(OBJS_MANDATORY); else rm -f $(OBJS_BONUS); fi
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       OBJS DONE          $(RESET)"
	@echo "$(GREEN)======================================$(RESET)"
	@echo
	$(CC) $(CFLAGS_NAME)
	@echo "$(GREEN)======================================$(RESET)"
	@echo "$(BOLD)$(BLUE)       Binary DONE          $(RESET)"
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
	@echo "$(BOLD)$(BLUE)       LOCAL CLEANING DONE          $(RESET)"
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
	@echo "$(BOLD)$(BLUE)       LOCAL FCLEANING DONE       $(RESET)"
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
