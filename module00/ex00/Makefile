# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 08:52:47 by joonasmykka       #+#    #+#              #
#    Updated: 2023/08/28 13:12:01 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++ -std=c++98
CFLAGS = -g -Wall -Wextra -Werror

FILES = megaphone.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "compiling"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "cleaning"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all