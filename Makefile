# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:06:49 by togauthi          #+#    #+#              #
#    Updated: 2024/11/15 10:59:47 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = libftprintf.a
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c \
	utils/arg.c \
	utils/stack.c \
	utils/push.c \
	utils/swap.c \
	utils/rotate.c \
	utils/reverse_rotate.c \
	utils/sort.c \
	utils/rank.c \
	src/index.c \
	src/bytes.c \
	src/little_sort.c \

OBJ_DIRS = objs/ \
	objs/utils \
	objs/src

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

OBJS = $(addprefix objs/, $(SRCS:.c=.o))

all: $(OBJ_DIRS) $(NAME)

$(PRINTF):
	@echo "$(YELLOW)Compiling printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C printf
	@mv printf/libftprintf.a ./

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Compiling push_swap... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@cc $(CFLAGS) -o $@ $(OBJS) $(PRINTF) $(LIBFT)
	@echo "$(GREEN)Done.${WHITE}"

objs/%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIRS):
	@mkdir $@

clean:
	@echo "$(YELLOW)Clearing printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]"
	@make --no-print-directory -C printf clean
	@rm -f $(PRINTF)
	@echo "$(YELLOW)Clearing libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]"
	@make --no-print-directory -C libft clean
	@rm -f $(LIBFT)
	@echo "$(YELLOW)Clearing objects... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@rm -rf $(OBJ_DIRS)
	@echo "$(GREEN)Done."

fclean: clean
	@echo "$(YELLOW)Clearing result...$(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)1$(WHITE)]"
	@rm -f $(NAME)
	@echo "$(GREEN)Done."

re: fclean all

.PHONY: all clean fclean re