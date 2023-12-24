# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 03:22:12 by azgaoua           #+#    #+#              #
#    Updated: 2023/12/24 03:22:14 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

OBJS = megaphone.o

FILES = megaphone.cpp

CXX = g++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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