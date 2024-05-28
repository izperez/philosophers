# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 12:48:04 by izperez           #+#    #+#              #
#    Updated: 2024/05/28 11:35:12 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = philo.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread #-g3 -fsanitize=address
RM = rm -f

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = main.c utils.c parse.c init_struct.c

.SILENT:
all: $(NAME)

$(NAME): $(LIBFT) $(SRC) $(INCLUDE)
				$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
				@echo "\033[32mPHILO COMPILED!\033[0m"
				
$(LIBFT):
			make -C $(LIBFT_DIR) all clean
			@echo "\033[33mLIBFT COMPILED!\033[0m"

clean:
			make -C $(LIBFT_DIR) fclean
fclean: clean
			$(RM) $(NAME)

re: fclean all $(LIBFT)