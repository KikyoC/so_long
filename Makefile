# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 11:34:01 by togauthi          #+#    #+#              #
#    Updated: 2024/11/18 15:17:34 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PRINTF = libftprintf.a
LIBFT = libft.a
GNL = gnl.a

CFLAGS = -Wall -Werror -Wextra -g
SRCS = so_long.c \
	srcs/map_manager/map-create.c \
	srcs/map_manager/map-delete.c \
	srcs/map_manager/checker/map-check.c \
	srcs/map_manager/checker/element-checker.c \
	srcs/map_manager/checker/solvable.c \
	srcs/map_manager/checker/move-check.c \
	srcs/utils/put_end.c \
	srcs/utils/last.c \
	srcs/utils/len.c \
	srcs/utils/movements.c \
	srcs/utils/refresh.c \

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

OBJS = $(addprefix objs/, $(SRCS:.c=.o))

OBJS_DIR = objs/ \
	objs/srcs/ \
	objs/srcs/map_manager/ \
	objs/srcs/map_manager/checker/ \
	objs/srcs/utils/

all: $(OBJS_DIR) $(NAME)

$(PRINTF):
	@echo "$(YELLOW)Compiling printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)4$(WHITE)]" 
	@make --no-print-directory -C printf
	@mv printf/libftprintf.a ./

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)4$(WHITE)]" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./

$(GNL):
	@echo "$(YELLOW)Compiling get_next_line... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)4$(WHITE)]"
	@make --no-print-directory -C gnl
	@mv gnl/gnl.a ./

$(NAME): $(PRINTF) $(LIBFT) $(GNL) $(OBJS)
	@echo "$(YELLOW)Compiling so_long... $(WHITE)[$(GREEN)4$(WHITE)/$(AQUA)4$(WHITE)]"
	@cc $(CFLAGS) -o $@ $(OBJS) $(PRINTF) $(LIBFT) $(GNL)
	@echo "$(GREEN)Done.${WHITE}"

objs/%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@

clean:
	@echo "$(YELLOW)Clearing printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)4$(WHITE)]"
	@make --no-print-directory -C printf clean
	@rm -f $(PRINTF)
	@echo "$(YELLOW)Clearing libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)4$(WHITE)]"
	@make --no-print-directory -C libft clean
	@rm -f $(LIBFT)
	@echo "$(YELLOW)Clearing gnl... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)4$(WHITE)]"
	@make --no-print-directory -C gnl clean
	@rm -f $(GNL)
	@echo "$(YELLOW)Clearing objects... $(WHITE)[$(GREEN)4$(WHITE)/$(AQUA)4$(WHITE)]"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Done."

fclean: clean
	@echo "$(YELLOW)Clearing result...$(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)1$(WHITE)]"
	@rm -f $(NAME)
	@echo "$(GREEN)Done."

re: fclean all

.PHONY: all clean fclean re