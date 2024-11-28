# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 11:34:01 by togauthi          #+#    #+#              #
#    Updated: 2024/11/28 10:48:04 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PRINTF = libftprintf.a
LIBFT = libft.a
GNL = gnl.a
MLX = mlx_linux/libmlx.a
MLX_DIR = mlx_linux/

CFLAGS = -Wall -Werror -Wextra -Iincludes -g
SRCS = mandatory/so_long.c \
	mandatory/srcs/map_manager/map-create.c \
	mandatory/srcs/map_manager/map-delete.c \
	mandatory/srcs/map_manager/checker/map-check.c \
	mandatory/srcs/map_manager/checker/element-checker.c \
	mandatory/srcs/map_manager/checker/solvable.c \
	mandatory/srcs/map_manager/checker/move-check.c \
	mandatory/srcs/utils/put_end.c \
	mandatory/srcs/utils/last.c \
	mandatory/srcs/utils/len.c \
	mandatory/srcs/utils/movements.c \
	mandatory/srcs/utils/refresh.c \
	mandatory/srcs/game/delete-game.c \
	mandatory/srcs/game/create-game.c \
	mandatory/srcs/player/player.c \

SRCS_BONUS = bonus/so_long.c \
	bonus/srcs/map_manager/map-create.c \
	bonus/srcs/map_manager/map-delete.c \
	bonus/srcs/map_manager/checker/map-check.c \
	bonus/srcs/map_manager/checker/element-checker.c \
	bonus/srcs/map_manager/checker/solvable.c \
	bonus/srcs/map_manager/checker/move-check.c \
	bonus/srcs/utils/put_end.c \
	bonus/srcs/utils/last.c \
	bonus/srcs/utils/len.c \
	bonus/srcs/utils/movements.c \
	bonus/srcs/utils/refresh.c \
	bonus/srcs/game/delete-game.c \
	bonus/srcs/game/create-game.c \
	bonus/srcs/player/player.c \
	bonus/srcs/animation/animation.c \
	bonus/srcs/animation/delete-animation.c \
	bonus/srcs/animation/counter.c \
	bonus/srcs/animation/create-animation.c \

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

OBJS = $(addprefix objs/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix objs/, $(SRCS_BONUS:.c=.o))

OBJS_DIR = objs/bonus \
	objs/bonus/srcs/ \
	objs/bonus/srcs/map_manager/ \
	objs/bonus/srcs/map_manager/checker/ \
	objs/bonus/srcs/utils/ \
	objs/bonus/srcs/game \
	objs/bonus/srcs/player \
	objs/bonus/srcs/animation \
	objs/mandatory \
	objs/mandatory/srcs/ \
	objs/mandatory/srcs/map_manager/ \
	objs/mandatory/srcs/map_manager/checker/ \
	objs/mandatory/srcs/utils/ \
	objs/mandatory/srcs/game \
	objs/mandatory/srcs/player \

all: $(MLX_DIR) $(OBJS_DIR) $(NAME)

$(PRINTF):
	@echo "$(YELLOW)Compiling printf... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)5$(WHITE)]" 
	@make --no-print-directory -C printf
	@mv printf/libftprintf.a ./

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)5$(WHITE)]" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./

$(GNL):
	@echo "$(YELLOW)Compiling get_next_line... $(WHITE)[$(GREEN)4$(WHITE)/$(AQUA)5$(WHITE)]"
	@make --no-print-directory -C gnl
	@mv gnl/gnl.a ./

$(MLX):
	@echo "$(YELLOW)Compiling minilibx... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)5$(WHITE)]"
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@make --no-print-directory -C mlx_linux
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="

$(MLX_DIR):
	@echo "$(YELLOW)Downloading minilibx"
	@mkdir -p mlx_linux
	@wget https://cdn.intra.42.fr/document/document/26767/minilibx-linux.tgz -O mlx_linux.tar.gz
	@tar -xf mlx_linux.tar.gz -C mlx_linux --strip-components 1
	@rm -f mlx_linux.tar.gz
	@echo "$(GREEN)Sucessfully downloaded minilibx"

$(NAME): $(MLX) $(PRINTF) $(LIBFT) $(GNL) $(OBJS)
	@echo "$(YELLOW)Compiling so_long... $(WHITE)[$(GREEN)5$(WHITE)/$(AQUA)5$(WHITE)]"
	@cc $(CFLAGS) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) $(MLX) $(PRINTF) $(LIBFT) $(GNL) -o $@
	@echo "$(GREEN)Done.${WHITE}"

objs/%.o: %.c
	@cc $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@

clean:
	@echo "$(YELLOW)Clearing printf... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)5$(WHITE)]"
	@make --no-print-directory -C printf clean
	@rm -f $(PRINTF)
	@echo "$(YELLOW)Clearing libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)5$(WHITE)]"
	@make --no-print-directory -C libft clean
	@rm -f $(LIBFT)
	@echo "$(YELLOW)Clearing gnl... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)5$(WHITE)]"
	@make --no-print-directory -C gnl clean
	@rm -f $(GNL)
	@echo "$(YELLOW)Clearing mlx... $(WHITE)[$(GREEN)4$(WHITE)/$(AQUA)5$(WHITE)]"
	@if [ -f "mlx_linux/Makefile" ]; then make --no-print-directory -C mlx_linux clean; fi;
	@echo "$(YELLOW)Clearing objects... $(WHITE)[$(GREEN)5$(WHITE)/$(AQUA)5$(WHITE)]"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Done."

install: $(MLX_DIR) $(MLX)

fclean: clean
	@echo "$(YELLOW)Clearing result...$(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)2$(WHITE)]"
	@rm -f $(NAME)
	@echo "$(YELLOW)Clearing mlx...$(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)2$(WHITE)]"
	@rm -rf mlx_linux
	@echo "$(GREEN)Done."

re: fclean all

bonus: $(MLX_DIR) $(OBJS_DIR) $(MLX) $(PRINTF) $(LIBFT) $(GNL) $(OBJS_BONUS)
	@echo "$(YELLOW)Compiling so_long... $(WHITE)[$(GREEN)5$(WHITE)/$(AQUA)5$(WHITE)]"
	@cc $(CFLAGS) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS_BONUS) $(MLX) $(PRINTF) $(LIBFT) $(GNL) -o $(NAME)
	@echo "$(GREEN)Done.${WHITE}"
	@echo "$(GREEN)Bonus sucessfully compiled.${WHITE}"

.PHONY: all clean fclean re install bonus