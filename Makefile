# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamachad <lamachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 20:06:17 by lamachad          #+#    #+#              #
#    Updated: 2025/02/26 19:38:36 by lamachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CC		:= cc
CFLAGS	:= -g3 -Wextra -Wall -Werror
LIBMLX	:= ./libraries/MLX42
LIBFT	:= ./libraries/libft
FLAGSMLX := -ldl -lglfw -pthread -lm
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
SRCS	:= ./src/main.c \
						./src/move.c \
						./src/render.c \
						./src/load.c \
						./src/validate.c \
						./src/flood_fill.c \
						./src/utils.c \
						./src/check_map.c \
						./src/size_map.c \

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -o $(NAME) $(FLAGSMLX)
	@echo "Linking complete: $(NAME)"

$(LIBMLX)/build/libmlx42.a:
	@echo "Building MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "MLX42 build complete."

$(LIBFT)/libft.a:
	@echo "Building libft..."
	@make -C $(LIBFT) --no-print-directory
	@echo "Libft build complete."

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@find $(LIBFT) -name "*.o" -delete
	@echo "Cleanup complete."

fclean: clean
	@echo "Cleaning up binary and libraries..."
	@rm -rf $(NAME)
	@find $(LIBFT) -name "*.a" -delete
	@echo "Full cleanup complete."

re: fclean all

.PHONY: all clean fclean re