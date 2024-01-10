# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 03:45:56 by azgaoua           #+#    #+#              #
#    Updated: 2024/01/09 19:58:40 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

OBJS = Contact.o Phonebook.o

FILES = Contact.cpp Phonebook.cpp

CXX = g++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all :  $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) :  $(OBJS) $(FILES)
	@echo "------>making the megaphone<------"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "--------->megaphone Done<---------"

clean:
	@echo " remove $(OBJS)"
	@$(RM) $(OBJS)

fclean:  clean
	@echo " clean --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all