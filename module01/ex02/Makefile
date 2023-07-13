# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 08:52:47 by joonasmykka       #+#    #+#              #
#    Updated: 2023/07/12 16:18:07 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++ -std=c++98
CFLAGS = -g -Wall -Wextra -Werror

FILES = main.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all