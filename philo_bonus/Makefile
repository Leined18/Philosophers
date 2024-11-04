# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/11/04 12:34:55 by danpalac         ###   ########.fr        #
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

BONUS	:= philo_bonus

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/

ACTIONS_DIR		:= actions/
CHILD_DIR		:= child/
DATA_DIR		:= data/
PHILO 		 	:= philo/
SIGNALS 		:= signals/
STATE_DIR		:= state/
SYNC_DIR		:= sync/
THREAD_DIR		:= thread/
UTILS_DIR		:= utils/

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -pthread -fsanitize=address -g3
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(INC) -I$(SRC_DIR)$(ACTIONS_DIR) -I$(SRC_DIR)$(CHILD_DIR) -I$(SRC_DIR)$(DATA_DIR) -I$(SRC_DIR)$(PHILO) -I$(SRC_DIR)$(SIGNALS) -I$(SRC_DIR)$(STATE_DIR) -I$(SRC_DIR)$(SYNC_DIR) -I$(SRC_DIR)$(THREAD_DIR) -I$(SRC_DIR)$(UTILS_DIR)

#==========SOURCES=BONUS============================================================#

ACTIONS_FILES := actions_bonus actions_utils_bonus
CHILD_FILES := child_bonus child_utils_bonus
DATA_FILES := clean_bonus init_bonus
PHILO_FILES := check_bonus
SIGNALS_FILES := handle_signals_bonus signals_utils_bonus
STATE_FILES := 
SYNC_FILES := 
THREAD_FILES := thread_bonus
UTILS_FILES := parse_bonus utils_bonus
MAIN_FILES := main_bonus

#==========FILES==============================================================#

SRC_FILES_BONUS+=$(addprefix $(ACTIONS_DIR), $(ACTIONS_FILES))
SRC_FILES_BONUS+=$(addprefix $(BONUS_DIR), $(BONUS_FILES))
SRC_FILES_BONUS+=$(addprefix $(CHILD_DIR), $(CHILD_FILES))
SRC_FILES_BONUS+=$(addprefix $(DATA_DIR), $(DATA_FILES))
SRC_FILES_BONUS+=$(addprefix $(PHILO), $(PHILO_FILES))
SRC_FILES_BONUS+=$(addprefix $(SIGNALS), $(SIGNALS_FILES))
SRC_FILES_BONUS+=$(addprefix $(STATE_DIR), $(STATE_FILES))
SRC_FILES_BONUS+=$(addprefix $(SYNC_DIR), $(SYNC_FILES))
SRC_FILES_BONUS+=$(addprefix $(THREAD_DIR), $(THREAD_FILES))
SRC_FILES_BONUS+=$(addprefix $(UTILS_DIR), $(UTILS_FILES))
SRC_FILES_BONUS+=$(MAIN_FILES)

SRCS_BONUS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJS_BONUS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))
DEPS_BONUS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES_BONUS)))

#==========RULES==============================================================#

all: bonus

bonus: $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(BONUS)$(DEF_COLOR)$(BOLD_BLUE)]$(BOLD_BLUE) compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(CYAN)[$(BONUS)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(BONUS)
	@echo "$(CYAN)[$(BONUS)]:\texec. files $(GREEN) => Cleaned!$(DEF_COLOR)"

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
