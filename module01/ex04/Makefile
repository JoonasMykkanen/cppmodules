# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 13:29:24 by joonasmykka       #+#    #+#              #
#    Updated: 2024/02/08 10:11:34 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = -I ./inc

NAME = sed

CC = c++ -std=c++11
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