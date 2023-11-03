# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 12:41:19 by jofoto            #+#    #+#              #
#    Updated: 2023/06/06 17:31:35 by jofoto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARIES	=	-lmlx -framework OpenGL -framework AppKit

FLAGS		=	-Wall -Wextra -Werror #-g -fsanitize=address

SRC			=	src/fdf.c src/draw_img.c src/rotate.c src/get_map.c src/init.c src/exit_handling.c

SRC_BONUS	=	bonus/fdf_bonus.c bonus/draw_img_bonus.c bonus/rotate_bonus.c bonus/get_map_bonus.c \
				bonus/init_bonus.c bonus/exit_handling_bonus.c bonus/thread_bonus.c bonus/controls_bonus.c

OBJ			=	$(SRC:%.c=%.o)

OBJ_BONUS	=	$(SRC_BONUS:%.c=%.o)

NAME		=	fdf

NAME_BONUS	=	fdf_bonus

LIBFT		=	libft/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT)
	cc -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT) $(LIBRARIES)

$(OBJ): %.o: %.c
	cc -c $? -o $@

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	cc -o $(NAME_BONUS) $(OBJ_BONUS) $(FLAGS) -pthread $(LIBFT) $(LIBRARIES)

$(OBJ_BONUS): %.o: %.c
	cc -c $? -o $@

$(LIBFT):
	cd libft && $(MAKE)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re noflag debug