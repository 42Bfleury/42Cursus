# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:58:48 by bfleury           #+#    #+#              #
#    Updated: 2025/02/17 11:24:16 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################### PROJECT ###################################


NAME						= minitalk
SERVER_NAME					= server
CLIENT_NAME					= client

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

OBJS_DIR_MSG				= "$(YELLOW)Creating $(NAME) $(OBJS_DIR) directory...		$(END)\c"

UTILS_OBJS_MSG				= "$(YELLOW)Generating $(NAME) utils object...		$(END)\c"
SERVER_OBJS_MSG				= "$(YELLOW)Generating $(NAME) $(SERVER_NAME) object...		$(END)\c"
CLIENT_OBJS_MSG				= "$(YELLOW)Generating $(NAME) $(CLIENT_NAME) object...		$(END)\c"

SERVER_MSG					= "$(GREEN)Generating $(NAME) $(SERVER_NAME) $(TYPEFILE)...	$(END)\c"
CLIENT_MSG					= "$(GREEN)Generating $(NAME) $(CLIENT_NAME) $(TYPEFILE)...	$(END)\c"

RM_OBJS_MSG					= "$(RED)Removing $(NAME) objects...			$(END)\c"
RM_OBJS_DIR_MSG				= "$(RED)Removing $(NAME) objs directory...		$(END)\c"
RM_SERVER_MSG				= "$(RED)Removing $(NAME) $(SERVER_NAME) $(TYPEFILE)...		$(END)\c"
RM_CLIENT_MSG				= "$(RED)Removing $(NAME) $(CLIENT_NAME) $(TYPEFILE)...		$(END)\c"


##################################### SRCS #####################################


UTILS_FILES					= minitalk_utils.c

SERVER_FILES				= server.c

CLIENT_FILES				= client.c


SRCS_DIR					= srcs
UTILS__SRCS					= $(addprefix $(SRCS_DIR)/, $(UTILS_FILES))
SERVER_SRCS					= $(addprefix $(SRCS_DIR)/, $(SERVER_FILES))
CLIENT_SRCS					= $(addprefix $(SRCS_DIR)/, $(CLIENT_FILES))

OBJS_DIR					= objs
UTILS_OBJS					= $(UTILS_FILES:%.c=$(OBJS_DIR)/%.o)
SERVER_OBJS					= $(SERVER_FILES:%.c=$(OBJS_DIR)/%.o)
CLIENT_OBJS					= $(CLIENT_FILES:%.c=$(OBJS_DIR)/%.o)


#################################### RULES #####################################


all:						$(NAME)

$(NAME):					$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):				$(LIB) $(UTILS_OBJS) $(SERVER_OBJS)
							@echo $(SERVER_MSG)
							@${CC} ${CFLAGS} $(SERVER_OBJS) $(UTILS_OBJS) $(LIBFLAGS) -o server
							@echo $(SUCCESS_MSG)

$(CLIENT_NAME):				$(LIB) $(UTILS_OBJS) $(CLIENT_OBJS)
							@echo $(CLIENT_MSG)
							@${CC} ${CFLAGS} $(CLIENT_OBJS) $(UTILS_OBJS) $(LIBFLAGS) -o client
							@echo $(SUCCESS_MSG)

$(LIB):
							@$(MAKE) $(LIBNAME) -C $(LIB_DIR)


#################################### OBJS ######################################


$(UTILS_OBJS):				$(UTILS__SRCS)
							@echo $(UTILS_OBJS_MSG)
							@mkdir -p objs
							@$(CC) $(CFLAGS) -c $< -o $@
							@echo $(SUCCESS_MSG)

$(SERVER_OBJS):				$(SERVER_SRCS)
							@echo $(SERVER_OBJS_MSG)
							@mkdir -p objs
							@$(CC) $(CFLAGS) -c $< -o $@
							@echo $(SUCCESS_MSG)

$(CLIENT_OBJS):				$(CLIENT_SRCS)
							@echo $(CLIENT_OBJS_MSG)
							@mkdir -p objs
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
							@echo $(RM_SERVER_MSG)
							@$(RM) $(SERVER_NAME)
							@echo $(SUCCESS_MSG)
							@echo $(RM_CLIENT_MSG)
							@$(RM) $(CLIENT_NAME)
							@echo $(SUCCESS_MSG)

fclean:						clean xclean

re:							fclean all

.PHONY:						clean fclean re