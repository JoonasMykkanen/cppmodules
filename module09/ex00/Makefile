# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 07:29:07 by joonasmykka       #+#    #+#              #
#    Updated: 2024/03/29 11:19:23 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

INC = -I ./inc

CC = c++

FLAGS = -std=c++17 -Wall -Werror -Wextra $(INC)

SRCDIR = src
OBJDIR = obj

SRCFILES = main.cpp BitcoinExchange.cpp

SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all