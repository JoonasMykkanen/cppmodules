# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 13:29:24 by joonasmykka       #+#    #+#              #
#    Updated: 2023/09/20 14:57:50 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = -I ./inc

NAME = sed

CC = c++ -std=c++98
CFLAGS = $(INC) -Wall -Wextra -Werror 

SRCDIR = src
OBJDIR = obj
SRCFILES = main.cpp
SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "compiling"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo "cleaning"
	@rm -rf $(OBJECTS)

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: files
files:
	@echo "removing .replace files"
	@rm -f files/*.replace