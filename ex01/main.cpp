/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:27 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/16 14:07:32 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phone;

	printWelcome();
	while (1) {
		std::string command = "";
		while (command != "ADD" && command != "SEARCH" && command != "EXIT")
		{
			std::cout << "                                   ";
			std::cout << "___________________________________________" << std::endl;
			std::cout << "this is the supported commands :  ";
			std::cout << "|Commands: |ADD       |SEARCH    |EXIT      |" << std::endl;
			std::cout << "                                   ";
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << "Enter a command: ";
			getline(std::cin, command);
			if (feof(stdin))
			{
				std::cin.clear();
				std::clearerr(stdin);
				std::cout << std::endl;
				continue;
			}
			if (command != "ADD" && command != "SEARCH" && command != "EXIT")
			{
				std::cout << "                                   ";
				std::cout << "Invalid command !!" << std::endl;
				continue;
			}
		}
		if (command == "EXIT")
		{
			phone.exit();
			break;
		}
		else if (command == "ADD")
		{
			phone.addContact(Contact());
			continue;
		}
		else if (command == "SEARCH")
		{
			phone.searchCommand(phone);
			continue;
		}
	}
	return (0);
}
