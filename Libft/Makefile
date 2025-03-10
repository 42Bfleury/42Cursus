# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 23:06:16 by bfleury           #+#    #+#              #
#    Updated: 2025/03/10 14:36:32 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a

TYPEFILE			= library

SRCS_DIR			= .
OBJS_DIR			= objs
INCLUDES			= .

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

################################## MESSAGES ####################################

BOLD				= \033[1m
RED					= \033[31m
YELLOW				= \033[33m
GREEN				= \033[32m
END					= \033[0m

ERASE				= "\r                                                                                \r"

SUCCESS_MSG			= "$(BOLD)$(GREEN)[SUCCESS]$(END)"

OBJS_DIR_MSG		= "$(YELLOW)Creating $(TYPEFILE) $(OBJS_DIR) directory...$(END)"
OBJS_MSG			= "$(YELLOW)Generating $< object...$(END)"

PROJECT_MSG			= "$(GREEN)Generating $(NAME) $(TYPEFILE)...		$(END)"
BONUS_MSG			= "$(GREEN)Generating $(NAME) bonus $(TYPEFILE)...	$(END)"

RM_OBJS_MSG			= "$(RED)Removing $(TYPEFILE) objects...		$(END)"
RM_OBJS_DIR_MSG		= "$(RED)Removing $(TYPEFILE) objs directory...	$(END)"
RM_PROJECT_MSG		= "$(RED)Removing $(TYPEFILE)...			$(END)"

#################################### FILES #####################################

FILES				= ft_atoi.c				\
					ft_bzero.c				\
					ft_calloc.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_itoa.c				\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_memcpy.c				\
					ft_memmove.c			\
					ft_memset.c				\
					ft_putchar_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					ft_putstr_fd.c			\
					ft_split.c				\
					ft_strchr.c				\
					ft_strdup.c				\
					ft_striteri.c			\
					ft_strjoin.c			\
					ft_strlcat.c			\
					ft_strlcpy.c			\
					ft_strlen.c				\
					ft_strmapi.c			\
					ft_strncmp.c			\
					ft_strnstr.c			\
					ft_strrchr.c			\
					ft_strtrim.c			\
					ft_substr.c				\
					ft_tolower.c			\
					ft_toupper.c

B_FILES				= ft_lstadd_back.c		\
					ft_lstadd_front.c		\
					ft_lstclear.c			\
					ft_lstdelone.c			\
					ft_lstiter.c			\
					ft_lstlast.c			\
					ft_lstmap.c				\
					ft_lstnew.c				\
					ft_lstsize.c

#################################### OBJS ######################################

OBJS				= $(FILES:%.c=$(OBJS_DIR)/%.o)
B_OBJS				= $(B_FILES:%.c=$(OBJS_DIR)/%.o)

#################################### RULES #####################################

all:				$(NAME)


$(NAME):			$(OBJS_DIR) $(OBJS)
					@printf $(ERASE)
					@printf $(PROJECT_MSG)
					@ar rcs $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo $(SUCCESS_MSG)

bonus:				$(NAME) $(B_OBJS)
					@printf $(ERASE)
					@printf $(BONUS_MSG)
					@ar rcs $(NAME) $(NAME) $(B_OBJS)
					@ranlib $(NAME)
					@echo $(SUCCESS_MSG)

$(OBJS_DIR):
					@printf $(OBJS_DIR_MSG)
					@mkdir -p objs

$(OBJS_DIR)/%.o:	%.c
					@printf $(ERASE)
					@printf $(OBJS_MSG)
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

#################################### CLEAN #####################################

clean:
					@printf $(RM_OBJS_DIR_MSG)
					@$(RM) $(OBJS_DIR)
					@echo $(SUCCESS_MSG)

xclean:
					@printf $(RM_PROJECT_MSG)
					@$(RM) $(NAME)
					@echo $(SUCCESS_MSG)

fclean:				clean xclean

re:					fclean all

.PHONY:				all bonus clean xclean fclean re
