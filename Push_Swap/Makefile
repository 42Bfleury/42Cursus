# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:58:48 by bfleury           #+#    #+#              #
#    Updated: 2025/02/16 05:49:30 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################### PROJECT ###################################


NAME						= push_swap

TYPEFILE					= executable

LIB_DIR						= lib
LIBNAME						= libftfull_bonus.a
LIB							= $(LIB_DIR)/$(LIBNAME)
LIBFLAGS					= -L$(LIB_DIR) -l$(LIBNAME:lib%.a=%)

CC							= cc
CFLAGS						= -Wall -Wextra -Werror

RM							= rm -rf


################################## MESSAGES ####################################


RED							= \033[31m
YELLOW						= \033[33m
GREEN						= \033[1;32m
END							= \033[0m

SUCCESS_MSG					= "$(GREEN)[SUCCESS]$(END)"

OBJS_DIR_MSG				= "$(YELLOW)Creating $(OBJS_DIR) directory...			$(END)\c"

PROJECT_OBJ_MSG				= "$(YELLOW)Generating $(NAME) object...			$(END)\c"

PROJECT_MSG					= "$(GREEN)Generating $(NAME) $(TYPEFILE)...		$(END)\c"

RM_OBJS_MSG					= "$(RED)Removing objects...				$(END)\c"
RM_OBJS_DIR_MSG				= "$(RED)Removing objs directory...			$(END)\c"
RM_PROJECT_MSG				= "$(RED)Removing $(NAME) $(TYPEFILE)...		$(END)\c"


##################################### SRCS #####################################


FILES						= push_swap.c			\
							ps_move.c				\
							ps_sort.c				\
							ps_parse.c				\
							ps_check.c				\
							ps_operations.c			\
							ps_calculations.c		\
							ps_min_max_utils.c		\
							ps_double_operations.c

SRCS_DIR					= srcs
SRCS						= $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS_DIR					= objs
OBJS						= $(FILES:%.c=$(OBJS_DIR)/%.o)


#################################### RULES #####################################


all:						$(NAME)

$(NAME):					$(LIB) $(OBJS_DIR) $(OBJS)
							@echo $(PROJECT_MSG)
							@${CC} ${CFLAGS} $(OBJS) $(LIBFLAGS) -o $(NAME)
							@echo $(SUCCESS_MSG)

$(LIB):
							@$(MAKE) $(LIBNAME) -C $(LIB_DIR)


#################################### OBJS ######################################


$(OBJS_DIR):
							@echo $(OBJS_DIR_MSG)
							@mkdir -p objs
							@echo $(SUCCESS_MSG)

$(OBJS_DIR)/%.o:			$(SRCS_DIR)/%.c
							@echo $(PROJECT_OBJ_MSG)
							@$(CC) $(CFLAGS) -c $< -o $@
							@echo $(SUCCESS_MSG)


#################################### CLEAN #####################################


clean:
							@$(MAKE) clean -C $(LIB_DIR)
							@echo $(RM_OBJS_MSG)
							@$(RM) $(OBJS)
							@echo $(SUCCESS_MSG)
							@echo $(RM_OBJS_DIR_MSG)
							@$(RM) $(OBJS_DIR)
							@echo $(SUCCESS_MSG)

xclean:
							@$(MAKE) xclean -C $(LIB_DIR)
							@echo $(RM_PROJECT_MSG)
							@$(RM) $(NAME)
							@echo $(SUCCESS_MSG)

fclean:						clean xclean

re:							fclean all

.PHONY:						clean fclean re