# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 07:29:07 by joonasmykka       #+#    #+#              #
#    Updated: 2024/04/10 15:09:42 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

INC = -I ./inc

CC = c++

FLAGS = -std=c++17 -Wall -Werror -Wextra $(INC)

SRCDIR = src
OBJDIR = obj
INCDIR = inc

HEADERFILES = $(SRCDIR)/PmergeMe.tpp $(INCDIR)/PmergeMe.hpp
SRCFILES = main.cpp 

SOURCES = $(patsubst %, $(SRCDIR)/%, $(SRCFILES))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCFILES))


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERFILES)
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