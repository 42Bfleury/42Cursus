# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:12:15 by bfleury           #+#    #+#              #
#    Updated: 2025/02/09 13:38:16 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				= libftprintf.a

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

FILES				= ft_printf.c			\
					ft_printf_utils.c		\
					ft_printf_utils_hexa.c

SRCS_DIR			= srcs
SRCS				= $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS_DIR			= objs
OBJS				= $(FILES:%.c=$(OBJS_DIR)/%.o)

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)

$(OBJS_DIR):
					@mkdir -p objs

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@rm -f $(NAME) $(PRINTF) $(LIB)

re:					fclean all

.PHONY:				debug clean fclean re
