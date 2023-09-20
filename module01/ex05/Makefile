# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 13:29:24 by joonasmykka       #+#    #+#              #
#    Updated: 2023/09/20 14:58:09 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = -I ./inc

NAME = ex05

CC = c++ -std=c++98
CFLAGS = $(INC) -Wall -Wextra -Werror 

SRCDIR = src
OBJDIR = obj
SRCFILES = main.cpp Harl.cpp
SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "compiling"

all: $(NAME)

clean:
	@echo "cleaning"
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
