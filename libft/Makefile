# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:50:32 by jofoto            #+#    #+#              #
#    Updated: 2023/01/22 17:22:09 by jofoto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strlcpy.c \
	  ft_strlcat.c ft_calloc.c ft_strdup.c ft_strtrim.c ft_substr.c \
	  ft_strjoin.c ft_split.c ft_strmapi.c ft_putchar_fd.c ft_striteri.c \
	  ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr_count.c \
	  ft_strndup.c is_char_in_set.c print_string_list.c ft_itoa_base.c \
	  ft_itoa_unsigned.c ft_itoa_unsigned_long.c get_next_line.c get_next_line_utils.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTFILES = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
			  ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o \
			  ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o \
			  ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_strlcpy.o \
			  ft_strlcat.o ft_calloc.o ft_strdup.o ft_strtrim.o ft_substr.o \
			  ft_strjoin.o ft_split.o ft_strmapi.o ft_putchar_fd.o ft_striteri.o \
			  ft_itoa.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strchr_count.o \
			  ft_strndup.o is_char_in_set.o print_string_list.o ft_itoa_base.o \
			  ft_itoa_unsigned.o ft_itoa_unsigned_long.o get_next_line.o get_next_line_utils.o

OBJECTFILES_BONUS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o \
			ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
			ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

NAME = libft.a

all: $(NAME)

$(NAME):
	cc -c $(SRC) $(FLAGS)
	ar rc $(NAME) $(OBJECTFILES)

bonus: fclean
	cc -c $(FLAGS) $(SRC_BONUS) $(SRC)
	ar rc $(NAME) $(OBJECTFILES_BONUS) $(OBJECTFILES)

debug: fclean
	cc -g -c $(FLAGS) $(SRC_BONUS) $(SRC)
	ar rc $(NAME) $(OBJECTFILES_BONUS) $(OBJECTFILES)

clean:
	rm -f $(OBJECTFILES) $(OBJECTFILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
