# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 17:39:13 by mfagri            #+#    #+#              #
#    Updated: 2021/11/27 17:42:10 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
INC = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
		  ft_printf_utils.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) 
		@ ar rcs $(NAME) $(OBJECTS)

%.o:%.c $(INC)
	${CC} $(CFLAGS) -c $< -o $@
clean : 
		 rm -rf $(OBJECTS)

fclean : clean
		 rm -rf $(NAME)

re : fclean all