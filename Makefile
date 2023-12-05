# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xortega <xortega@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 12:09:10 by xortega           #+#    #+#              #
#    Updated: 2023/11/30 15:01:50 by xortega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := so_long
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -Imlx #-fsanitize=address -g3
SOURCES			:= so_long.c so_map.c so_tiles.c so_checks.c so_exits.c so_mlx.c so_movements.c
BSOURCES		:= so_bonus_long.c so_bonus_map.c so_bonus_tiles.c so_bonus_checks.c so_bonus_exits.c so_bonus_mlx.c so_bonus_movements.c so_bonus_p.c so_bonus_c.c so_bonus.c
OBJECTS			:= $(SOURCES:.c=.o)
BOBJECTS		:= $(BSOURCES:.c=.o)
LIBFT			:= libft.a
MLX				:= libmlx.a

all: $(NAME)

.SILENT:

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) -o $(NAME)
	chmod 777 $(NAME)

bonus: $(LIBFT) $(MLX) $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) -Lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) -o $(NAME)
	chmod 777 $(NAME)

$(LIBFT):
	@make -C Libft 2> /dev/null
	cp Libft/libft.a $(LIBFT)
	
$(MLX):
	@make -C mlx 2> /dev/null
	cp mlx/libmlx.a $(MLX)

clean:
	make clean -C Libft
	make clean -C mlx
	rm -f $(OBJECTS)
	rm -f $(BOBJECTS)

fclean: clean
	printf "\033[1;31m❌ERASED❌\n"
	rm -f $(NAME)
	rm -f libft.a
	rm -f libmlx.a

rclean:	clean
	printf "✅REMAKE✅\n"
	rm -f $(NAME)
	rm -f libft.a
	rm -f libmlx.a

re: rclean all
rebonus: rclean bonus

.PHONY: all rclean clean fclean re bonus rebonus