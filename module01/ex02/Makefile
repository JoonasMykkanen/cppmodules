# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 08:52:47 by joonasmykka       #+#    #+#              #
#    Updated: 2023/08/29 09:20:25 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++ -std=c++98
CFLAGS = -g -Wall -Wextra -Werror

FILES = main.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "compiling"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	@echo "cleaning"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all