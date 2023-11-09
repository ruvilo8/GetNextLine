# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolo <lolo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:47:07 by lolo              #+#    #+#              #
#    Updated: 2023/11/09 15:48:58 by lolo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

AR = ar
AR_FLAG = crs

CC = gcc
CC_FLAG = -Wall -Werror -Wextra

RM = rm
RM_FLAG = -f

INCLUDES = ./get_next_line.h

SRC = \
      ./get_next_line.c \
      ./get_next_line_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

clean:
	$(RM) $(RM_FLAG) $(OBJS)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

$(OBJS): %.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re bonus
