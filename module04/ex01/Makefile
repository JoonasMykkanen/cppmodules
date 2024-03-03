# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 11:43:45 by joonasmykka       #+#    #+#              #
#    Updated: 2024/02/08 10:11:34 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

INC = -I ./inc

CC = c++

FLAGS = -std=c++11 -Wall -Werror -Wextra $(INC)

SRCDIR = src
OBJDIR = obj

SRCFILES = main.cpp
SRCFILES += Animal.cpp
SRCFILES += Cat.cpp
SRCFILES += Dog.cpp
SRCFILES += WrongCat.cpp
SRCFILES += WrongAnimal.cpp
SRCFILES += Brain.cpp

SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all