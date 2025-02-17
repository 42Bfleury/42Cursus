# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:12:15 by bfleury           #+#    #+#              #
#    Updated: 2025/02/16 21:52:41 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################# LIBFTFULL ####################################


NAME						= libftfull.a
BONUS						= libftfull_bonus.a

TYPEFILE					= library

LIB_DIR						= .
OBJS_DIR					= objs

CC							= cc
CFLAGS						= -Wall -Wextra -Werror

RM							= rm -rf


################################## MESSAGES ####################################


RED							= \033[31m
YELLOW						= \033[33m
GREEN						= \033[1;32m
END							= \033[0m

SUCCESS_MSG					= "$(GREEN)[SUCCESS]$(END)"

OBJS_DIR_MSG				= "$(YELLOW)Creating $(TYPEFILE) $(OBJS_DIR) directory...		$(END)\c"

LIBFT_OBJ_MSG				= "$(YELLOW)Generating Libft object...			$(END)\c"
LIBFT_B_OBJ_MSG				= "$(YELLOW)Generating Libft bonus object...		$(END)\c"
LIB_GNL_OBJ_MSG				= "$(YELLOW)Generating GNL object...			$(END)\c"
# LIB_GNL_B_OBJ_MSG			= "$(YELLOW)Generating GNL bonus object...			$(END)\c"
LIB_PRINTF_OBJ_MSG			= "$(YELLOW)Generating Ft_Printf object...			$(END)\c"

LIBFTFULL_MSG				= "$(GREEN)Generating $(NAME) $(TYPEFILE)...		$(END)\c"
LIBFTFULL_B_MSG				= "$(GREEN)Generating $(BONUS) $(TYPEFILE)...		$(END)\c"
LIBFT_MSG					= "$(GREEN)Generating $(LIBFT) $(TYPEFILE)...			$(END)\c"
LIBFT_B_MSG					= "$(GREEN)Generating $(LIBFT_BONUS) $(TYPEFILE)...		$(END)\c"
LIB_GNL_MSG					= "$(GREEN)Generating $(LIB_GNL) $(TYPEFILE)...			$(END)\c"
# LIB_GNL_B_MSG				= "$(GREEN)Generating $(LIB_GNL_BONUS) $(TYPEFILE)...		$(END)\c"
LIB_PRINTF_MSG				= "$(GREEN)Generating $(LIB_PRINTF) $(TYPEFILE)...		$(END)\c"


RM_OBJS_MSG					= "$(RED)Removing $(TYPEFILE) objects...			$(END)\c"
RM_OBJS_DIR_MSG				= "$(RED)Removing $(TYPEFILE) objs directory...		$(END)\c"
RM_LIBS_MSG					= "$(RED)Removing $(TYPEFILE)...				$(END)\c"


#################################### LIBFT ####################################


LIBFT						= libft.a
LIBFT_BONUS					= libft_bonus.a
LIBFT_DIR					= $(LIB_DIR)/Libft
LIBFT_SRCS_DIR				= $(LIBFT_DIR)/srcs
LIBFT_INCLUDES				= $(LIBFT_DIR)/includes
LIBFT_B_SRCS_DIR			= $(LIBFT_DIR)/srcs_bonus

LIBFT_FILES					= ft_atoi.c					\
							ft_bzero.c					\
							ft_calloc.c					\
							ft_isalnum.c				\
							ft_isalpha.c				\
							ft_isascii.c				\
							ft_isdigit.c				\
							ft_isprint.c				\
							ft_itoa.c					\
							ft_memchr.c					\
							ft_memcmp.c					\
							ft_memcpy.c					\
							ft_memmove.c				\
							ft_memset.c					\
							ft_putchar_fd.c				\
							ft_putendl_fd.c				\
							ft_putnbr_fd.c				\
							ft_putstr_fd.c				\
							ft_split.c					\
							ft_strchr.c					\
							ft_strdup.c					\
							ft_striteri.c				\
							ft_strjoin.c				\
							ft_strlcat.c				\
							ft_strlcpy.c				\
							ft_strlen.c					\
							ft_strmapi.c				\
							ft_strncmp.c				\
							ft_strnstr.c				\
							ft_strrchr.c				\
							ft_strtrim.c				\
							ft_substr.c					\
							ft_tolower.c				\
							ft_toupper.c

LIBFT_B_FILES				= ft_lstadd_back.c			\
							ft_lstadd_front.c			\
							ft_lstclear.c				\
							ft_lstdelone.c				\
							ft_lstiter.c				\
							ft_lstlast.c				\
							ft_lstmap.c					\
							ft_lstnew.c					\
							ft_lstsize.c

LIBFT_SRCS					= $(addprefix $(LIBFT_SRCS_DIR)/, $(LIBFT_FILES))
LIBFT_SRCS					+= $(addprefix $(LIBFT_B_SRCS_DIR)/, $(LIBFT_B_FILES))

LIBFT_OBJS					= $(LIBFT_FILES:%.c=$(OBJS_DIR)/%.o)
LIBFT_B_OBJS				= $(LIBFT_B_FILES:%.c=$(OBJS_DIR)/%.o)


##################################### GNL #####################################


LIB_GNL						= libgnl.a
LIB_GNL_DIR					= $(LIB_DIR)/GNL
LIB_GNL_SRCS_DIR			= $(LIB_GNL_DIR)/srcs
LIB_GNL_INCLUDES			= $(LIB_GNL_DIR)/includes

# LIB_GNL_BONUS				= libgnl_bonus.a
# LIB_GNL_B_SRCS_DIR			= $(LIB_GNL_DIR)/srcs_bonus

LIB_GNL_FILES				= get_next_line.c			\
							get_next_line_utils.c

# LIB_GNL_B_FILES				= get_next_line_bonus.c		\
							get_next_line_utils_bonus.c

LIB_GNL_SRCS				= $(addprefix $(LIB_GNL_SRCS_DIR)/, $(LIB_GNL_FILES))
# LIB_GNL_B_SRCS				= $(addprefix $(LIB_GNL_B_SRCS_DIR)/, $(LIB_GNL_B_FILES))

LIB_GNL_OBJS				= $(LIB_GNL_FILES:%.c=$(OBJS_DIR)/%.o)
# LIB_GNL_B_OBJS				= $(LIB_GNL_B_FILES:%.c=$(OBJS_DIR)/%.o)


#################################### PRINTF ###################################


LIB_PRINTF					= libftprintf.a
LIB_PRINTF_DIR				= $(LIB_DIR)/Ft_Printf
LIB_PRINTF_SRCS_DIR			= $(LIB_PRINTF_DIR)/srcs
LIB_PRINTF_INCLUDES			= $(LIB_PRINTF_DIR)/includes

LIB_PRINTF_FILES			= ft_printf.c				\
							ft_printf_utils.c			\
							ft_printf_utils_hexa.c

LIB_PRINTF_SRCS				= $(addprefix $(LIB_PRINTF_SRCS_DIR)/, $(LIB_PRINTF_FILES))

LIB_PRINTF_OBJS				= $(LIB_PRINTF_FILES:%.c=$(OBJS_DIR)/%.o)


#################################### RULES ####################################


###						###### ALL ######

all:						$(NAME)

all_lib:					$(LIBFT) $(LIB_GNL) $(LIB_PRINTF)

all_lib_bonus:				$(LIBFT_BONUS) $(LIB_GNL) $(LIB_PRINTF)
# all_lib_bonus:				$(LIBFT_BONUS) $(LIB_GNL_BONUS) $(LIB_PRINTF)

###						##### FULL #####

$(NAME):					$(OBJS_DIR) $(LIBFT_OBJS) $(LIB_GNL_OBJS) $(LIB_PRINTF_OBJS)
							@echo $(LIBFTFULL_MSG)
							@ar rc $(LIB_DIR)/$(NAME) $(LIBFT_OBJS) $(LIB_GNL_OBJS) $(LIB_PRINTF_OBJS)
							@ranlib $(LIB_DIR)/$(NAME)
							@echo $(SUCCESS_MSG)

bonus:						$(BONUS)

# $(BONUS):					$(OBJS_DIR) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_B_OBJS) $(LIB_PRINTF_OBJS)
$(BONUS):					$(OBJS_DIR) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_OBJS) $(LIB_PRINTF_OBJS)
							@echo $(LIBFTFULL_B_MSG)
#							@ar rc $(LIB_DIR)/$(BONUS) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_B_OBJS) $(LIB_PRINTF_OBJS)
							@ar rc $(LIB_DIR)/$(BONUS) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_OBJS) $(LIB_PRINTF_OBJS)
							@ranlib $(LIB_DIR)/$(BONUS)
							@echo $(SUCCESS_MSG)


###						##### LIBFT #####

$(LIBFT):					$(OBJS_DIR) $(LIBFT_OBJS)
							@echo $(LIBFT_MSG)
							@ar rc $(LIB_DIR)/$(LIBFT) $(LIBFT_OBJS)
							@ranlib $(LIB_DIR)/$(LIBFT)
							@echo $(SUCCESS_MSG)

$(LIBFT_BONUS):				$(OBJS_DIR) $(LIBFT_OBJS) $(LIBFT_B_OBJS)
							@echo $(LIBFT_B_MSG)
							@ar rc $(LIB_DIR)/$(LIBFT_BONUS) $(LIBFT_OBJS) $(LIBFT_B_OBJS)
							@ranlib $(LIB_DIR)/$(LIBFT_BONUS)
							@echo $(SUCCESS_MSG)

###						###### GNL ######

$(LIB_GNL):					$(OBJS_DIR) $(LIB_GNL_OBJS)
							@echo $(LIB_GNL_MSG)
							@ar rc $(LIB_DIR)/$(LIB_GNL) $(LIB_GNL_OBJS)
							@ranlib $(LIB_DIR)/$(LIB_GNL)
							@echo $(SUCCESS_MSG)

#$(LIB_GNL_BONUS):			$(OBJS_DIR) $(LIB_GNL_B_OBJS)
#							@echo $(LIB_GNL_B_MSG)
#							@ar rc $(LIB_DIR)/$(LIB_GNL_BONUS) $(LIB_GNL_B_OBJS)
#							@ranlib $(LIB_DIR)/$(LIB_GNL_BONUS)
#							@echo $(SUCCESS_MSG)

###						##### PRINTF #####

$(LIB_PRINTF):				$(OBJS_DIR) $(LIB_PRINTF_OBJS)
							@echo $(LIB_PRINTF_MSG)
							@ar rc $(LIB_DIR)/$(LIB_PRINTF) $(LIB_PRINTF_OBJS)
							@ranlib $(LIB_DIR)/$(LIB_PRINTF)
							@echo $(SUCCESS_MSG)


#################################### OBJS ######################################


$(OBJS_DIR):
							@echo $(OBJS_DIR_MSG)
							@mkdir -p $(OBJS_DIR)
							@echo $(SUCCESS_MSG)

###						##### LIBFT #####

$(OBJS_DIR)/%.o:			$(LIBFT_SRCS_DIR)/%.c
							@echo $(LIBFT_OBJ_MSG)
							@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES) -c $< -o $@
							@echo $(SUCCESS_MSG)

$(OBJS_DIR)/%.o:			$(LIBFT_B_SRCS_DIR)/%.c
							@echo $(LIBFT_B_OBJ_MSG)
							@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDES) -c $< -o $@
							@echo $(SUCCESS_MSG)

###						###### GNL ######

$(OBJS_DIR)/%.o:			$(LIB_GNL_SRCS_DIR)/%.c
							@echo $(LIB_GNL_OBJ_MSG)
							@$(CC) $(CFLAGS) -I$(LIB_GNL_INCLUDES) -c $< -o $@
							@echo $(SUCCESS_MSG)

#$(OBJS_DIR)/%.o:			$(LIB_GNL_B_SRCS_DIR)/%.c
#							@echo $(LIB_GNL_B_OBJ_MSG)
#							@$(CC) $(CFLAGS) -I$(LIB_GNL_INCLUDES) -c $< -o $@
#							@echo $(SUCCESS_MSG)

###						##### PRINTF #####

$(OBJS_DIR)/%.o:			$(LIB_PRINTF_SRCS_DIR)/%.c
							@echo $(LIB_PRINTF_OBJ_MSG)
							@$(CC) $(CFLAGS) -I$(LIB_PRINTF_INCLUDES) -c $< -o $@
							@echo $(SUCCESS_MSG)


#################################### CLEAN #####################################

clean:
							@echo $(RM_OBJS_MSG)
#							@$(RM) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_OBJS) $(LIB_GNL_B_OBJS) $(LIB_PRINTF_OBJS)
							@$(RM) $(LIBFT_OBJS) $(LIBFT_B_OBJS) $(LIB_GNL_OBJS) $(LIB_GNL_OBJS) $(LIB_PRINTF_OBJS)
							@echo $(SUCCESS_MSG)
							@echo $(RM_OBJS_DIR_MSG)
							@$(RM) $(OBJS_DIR)
							@echo $(SUCCESS_MSG)

xclean:
							@echo $(RM_LIBS_MSG)
#							@$(RM) $(NAME) $(BONUS) $(LIBFT) $(LIBFT_BONUS) $(LIB_GNL) $(LIB_GNL_BONUS) $(LIB_PRINTF)
							@$(RM) $(NAME) $(BONUS) $(LIBFT) $(LIBFT_BONUS) $(LIB_GNL) $(LIB_PRINTF)
							@echo $(SUCCESS_MSG)
fclean:						clean xclean

re:							fclean all

.PHONY:						clean fclean re
