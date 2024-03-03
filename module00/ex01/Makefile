# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 08:52:47 by joonasmykka       #+#    #+#              #
#    Updated: 2024/02/08 10:11:34 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++ -std=c++11
INCLUDE = -I ./include
CFLAGS = -g -Wall -Werror -Wextra $(INCLUDE)

SRC = \
	main.cpp \
	Contact.cpp \
	PhoneBook.cpp

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "compiling"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	@echo "cleaning"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
