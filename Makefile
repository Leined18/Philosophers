# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/10/25 12:37:03 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

# Basic Colors

BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# Bright Colors

BOLD_BLACK  = \033[1;30m
BOLD_RED    = \033[1;31m
BOLD_GREEN  = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_MAGENTA= \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_WHITE  = \033[1;37m

# Extended Colors (256 colors)
ORANGE      = \033[38;5;208m
WINE        = \033[38;5;88m
LIME        = \033[38;5;190m
TURQUOISE   = \033[38;5;38m
LIGHT_PINK  = \033[38;5;13m
DARK_GRAY   = \033[38;5;235m
LIGHT_RED   = \033[38;5;203m
LIGHT_BLUE  = \033[38;5;75m

BRIGHT_BLUE = \033[38;5;27m
BRIGHT_GREEN= \033[38;5;46m
BRIGHT_YELLOW=\033[38;5;226m
BRIGHT_CYAN = \033[38;5;51m
BRIGHT_WHITE= \033[38;5;231m

# Reseteo de color
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
CLEAR_LINE  = \033[2K
MOVE_UP     = \033[1A

#==========NAMES===============================================================#

NAME		:= philo
BONUS_NAME	:= philo_bonus

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/

ACTIONS_DIR		:= actions/
DATA_DIR		:= data/
MAIN_DIR		:= main/
UTILS_DIR		:= utils/
THREAD_DIR		:= thread/


#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address -pthread
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(INC)


#==========SOURCES============================================================#

MAIN_FILES := main check
DATA_FILES := init_data free_data
ACTIONS_FILES := actions actions_utils life_cycle
UTILS_FILES := utils parse
THREAD_FILES := thread

#==========BONUS==FILES========================================================#

BONUS_FILES := main_bonus clean_bonus init_bonus
BONUS_DIR := bonus/

#==========FILES==============================================================#

SRC_FILES+=$(addprefix $(MAIN_DIR), $(MAIN_FILES))
SRC_FILES+=$(addprefix $(DATA_DIR), $(DATA_FILES))
SRC_FILES+=$(addprefix $(ACTIONS_DIR), $(ACTIONS_FILES))
SRC_FILES+=$(addprefix $(UTILS_DIR), $(UTILS_FILES))
SRC_FILES+=$(addprefix $(THREAD_DIR), $(THREAD_FILES))

SRC_FILES_BONUS+=$(addprefix $(BONUS_DIR), $(BONUS_FILES))
SRC_FILES_BONUS+=$(addprefix $(UTILS_DIR), $(UTILS_FILES))
SRC_FILES_BONUS+=$(addprefix $(DATA_DIR), free_data)

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS_BONUS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))

OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJS_BONUS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
DEPS_BONUS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES_BONUS)))

#==========RULES==============================================================#

all: $(NAME)

bonus: $(BONUS_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)$(BONUS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) -DBONUS $(IFLAGS) -MP -MMD -c $< -o $@

$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -DBONUS $(OBJS_BONUS) -o $(BONUS_NAME)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(BONUS_NAME)$(DEF_COLOR)$(BOLD_BLUE)]$(BOLD_BLUE) compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(NAME) $(BONUS_NAME)
	@echo "$(CYAN)[$(NAME)]:\texec. files $(GREEN) => Cleaned!$(DEF_COLOR)"
	

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
