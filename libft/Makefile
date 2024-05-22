# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 10:30:52 by izperez           #+#    #+#              #
#    Updated: 2024/05/21 12:43:14 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c ft_strchr.c ft_strlcpy.c \
					ft_strlcat.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
					ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c \
					ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_free.c ft_gnl.c \
					ft_printf.c pf_isnegative.c pf_putnbr.c pf_putchar.c pf_putstr.c \
					ps_atol.c ft_strcmp.c ft_isspace.c

SRC_B			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstfind.c
					
OBJS				= $(SRCS:.c=.o)
OBJS_BONUS			= $(SRC_B:.c=.o)

NAME			= libft.a
CC				= gcc
CFLAGS			= -c -Wall -Wextra -Werror
RM				= rm -f
INCLUDE			= libft.h


.SILENT:
all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(OBJS):		$(SRCS) $(INCLU DE)
				$(CC) $(CFLAGS) $(SRCS)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS)