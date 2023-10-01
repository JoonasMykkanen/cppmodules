# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 11:43:45 by joonasmykka       #+#    #+#              #
#    Updated: 2023/10/01 12:16:39 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

INC = -I ./inc

CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra $(INC)

SRCDIR = src
OBJDIR = obj

SRCFILES = main.cpp


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