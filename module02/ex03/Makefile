# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 13:29:24 by joonasmykka       #+#    #+#              #
#    Updated: 2023/09/20 11:20:48 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = -I ./inc

NAME = ex03

CC = c++ -std=c++98
CFLAGS = $(INC) -Wall -Wextra -Werror 

SRCDIR = src
OBJDIR = obj
SRCFILES = main.cpp Fixed.cpp Point.cpp bsp.cpp
SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
