# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 03:45:56 by azgaoua           #+#    #+#              #
#    Updated: 2024/01/16 10:06:53 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

OBJS = Contact.o PhoneBook.o main.o

FILES = Contact.cpp PhoneBook.cpp main.cpp

CXX = c++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all :  $(NAME)

$(NAME) :  $(OBJS) $(FILES)
	@echo "------>making the megaphone<------"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "--------->megaphone Done<---------"

%.o: %.cpp Phonebook.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo " remove $(OBJS)"
	@$(RM) $(OBJS)

fclean:  clean
	@echo " clean --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all