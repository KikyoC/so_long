# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 11:34:01 by togauthi          #+#    #+#              #
#    Updated: 2024/11/15 11:35:57 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PRINTF = libftprintf.a
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra
SRCS = so_long.c \

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	@echo "$(YELLOW)Compiling printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C printf
	@mv printf/libftprintf.a ./

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Compiling so_long... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@cc $(CFLAGS) -o $@ $(OBJS) $(PRINTF) $(LIBFT)
	@echo "$(GREEN)Done.${WHITE}"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@


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