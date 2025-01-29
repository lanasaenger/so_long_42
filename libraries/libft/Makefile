# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 21:00:56 by lamachad          #+#    #+#              #
#    Updated: 2025/01/20 18:46:23 by lamachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_toupper.c ft_isalpha.c ft_isdigit.c ft_strlen.c ft_memset.c \
      ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_atoi.c \
	  ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_memcpy.c ft_memmove.c \
	  ft_calloc.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_strnstr.c ft_strdup.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putchar_fd.c ft_putnbr_fd.c ft_substr.c ft_strmapi.c  ft_striteri.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \ get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

CC = cc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c libft.h
	$(CC) $(C_FLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
