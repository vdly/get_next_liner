# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/01 00:06:02 by jodehii           #+#    #+#              #
#    Updated: 2026/09/06 22:27:14 by jodehii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -O0
AR		= ar -rcs

SRCS	=	get_next_line.c \
			get_next_line_utils.c \

OBJ		=	$(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all	: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re