# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/01 00:06:02 by jodehii           #+#    #+#              #
#    Updated: 2026/09/01 00:07:09 by jodehii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs

SRCS	= 	
OBJ		= $(SRCS:.c=.o)

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