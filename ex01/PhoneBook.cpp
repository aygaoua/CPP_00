/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:17:06 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/18 15:50:04 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*-----------------------------NON CLASS MEMBERS-----------------------------*/

/*1*/

void printWelcome(void) {
	std::cout << "                                   ";
	std::cout << "------->> Welcome to the PhoneBook <<-------" << std::endl;
}

/*2*/

bool valid(std::string str) {
	for (unsigned long i = 0; i < str.length(); i++) {
		if (str[i] == '\t')
			return (false);
	}
	return (true);
}

/*3*/

bool is_number(std::string str) {
	if (str[0] == '+')
		str.erase(0, 1);
	if (!std::isdigit(str[0]))
		return (false);
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]) && str[i] != ' ')
			return (false);
	}
	return (true);
}
/* ************************************************************************** */

/*-----------------------------CLASS MEMBERS-----------------------------*/

/*1*/

PhoneBook::PhoneBook() {
	_nb_contacts = 0;
}

/*2*/

void PhoneBook::addContact(Contact contact) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	static int _nbContacts = 1;

	while (first_name == "") {
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		while (std::isspace(first_name[0]))
			first_name.erase(0, 1);
		if (std::feof(stdin)) {
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		else if (first_name == "" || valid(first_name) == false)
		{
			std::cout << "Invalid first name" << std::endl;
			first_name = "";
		}
	}
	contact.setFirstName(first_name);
	while (last_name == "") {
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		while (std::isspace(last_name[0]))
			last_name.erase(0, 1);
		if (std::feof(stdin)) {
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		else if (last_name == "" || valid(last_name) == false)
		{
			std::cout << "Invalid last name" << std::endl;
			last_name = "";
		}
	}
	contact.setLastName(last_name);
	while (nickname == "") {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		while (std::isspace(nickname[0]))
			nickname.erase(0, 1);
		if (std::feof(stdin)) {
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		else if (nickname == "" || valid(nickname) == false)
		{
			std::cout << "Invalid nickname" << std::endl;
			nickname = "";
		}
	}
	contact.setNickname(nickname);
	while (phone_number == "" || !is_number(phone_number)) {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		while (std::isspace(phone_number[0]))
			phone_number.erase(0, 1);
		if (std::feof(stdin)) {
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		else if (phone_number == "" || !is_number(phone_number))
			std::cout << "Invalid phone number" << std::endl;
		else {
			for (unsigned long i = 0; i < phone_number.length(); i++) {
				if (std::isspace(phone_number[i])) {
					phone_number.erase(i, 1);
					i--;
				}
			}
		}
	}
	contact.setPhoneNumber(phone_number);
	while (darkest_secret == "") {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkest_secret);
		while (std::isspace(darkest_secret[0]))
			darkest_secret.erase(0, 1);
		if (std::feof(stdin)) {
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		else if (darkest_secret == "")
			std::cout << "Invalid darkest secret" << std::endl;
	}
	contact.setDarkestSecret(darkest_secret);
	_nbContacts %= 9;
	if (_nbContacts == 0)
		_nbContacts = 1;
	std::cout << "Contact " << _nbContacts << " added" << std::endl;
	if (_nbContacts > this->_nb_contacts)
		this->_nb_contacts = _nbContacts;
	_contacts[_nbContacts - 1] = contact;
	_nbContacts++;
}

/*3*/

int PhoneBook::getNbContacts() {
	return this->_nb_contacts;
}

/*4*/

void PhoneBook::searchCommand(PhoneBook &phone) {
	int index = 0;
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	for (int i = 0; i < phone.getNbContacts(); i++) {
		/*-------------------------------Index------------------------------*/
		std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
		/*-----------------------------FirstName----------------------------*/
		std::cout << std::setw(10) << std::right << \
					(phone.getContact(i).getFirstName().length() > 10 ? \
					(phone.getContact(i).getFirstName().substr(0, 9) + ".") : \
					phone.getContact(i).getFirstName()) << "|";
		/*------------------------------LastName---------------------------*/
		std::cout << std::setw(10) << std::right << \
					(phone.getContact(i).getLastName().length() > 10 ? \
					(phone.getContact(i).getLastName().substr(0, 9) + ".") : \
					phone.getContact(i).getLastName()) << "|";
		/*------------------------------Nickname---------------------------*/
		std::cout << std::setw(10) << std::right << \
					(phone.getContact(i).getNickname().length() > 10 ? \
					(phone.getContact(i).getNickname().substr(0, 9) + ".") : \
					phone.getContact(i).getNickname()) << "|";
		std::cout << std::endl;
		std::cout << " -------------------------------------------" << std::endl;
	}
	while ((index < 1 || index > 8) || \
			(phone.getContact(index).getFirstName() != "" && \
				phone.getContact(index).getLastName() != "" && \
				phone.getContact(index).getNickname() != "" && \
				phone.getContact(index).getPhoneNumber() != "" && \
				phone.getContact(index).getDarkestSecret() != "")) {   
		std::string index_s = "";
		while (index_s == "") {
			std::cout << "Enter index: ";
			std::getline(std::cin, index_s);
			if (index_s[0] == '+')
				index_s.erase(0, 1);
			while (std::isspace(index_s[0]) || index_s[0] == '0')
				index_s.erase(0, 1);
			if (std::feof(stdin)) {
				std::cin.clear();
				std::clearerr(stdin);
				std::cout << std::endl;
				continue;
			}
			else if (index_s == "")
				std::cout << "Invalid index" << std::endl;
			continue;
		}
		if (!std::isdigit(index_s[0]) || index_s.length() != 1) {
			std::cout << "Invalid index" << std::endl;
			std::cout << "the range available is from 1 to 8" << std::endl;
			continue;
		}
		index = index_s[0] - '0';
		if (index < 1 || index > 8) {
			std::cout << "Invalid index" << std::endl;
			std::cout << "the range available is from 1 to 8" << std::endl;
			continue;
		}
		else if (phone.getContact(index - 1).getFirstName() != "" && \
					phone.getContact(index - 1).getLastName() != "" && \
					phone.getContact(index - 1).getNickname() != "" && \
					phone.getContact(index - 1).getPhoneNumber() != "" && \
					phone.getContact(index - 1).getDarkestSecret() != "") {
			PhoneBook::searchContact(index - 1);
			break;
		}
		else {
			std::cout << "No contact at this index" << std::endl;
			break;
		}
	}
}

/*5*/

Contact PhoneBook::getContact(int index) {
	return this->_contacts[index];
}

/*6*/

void PhoneBook::searchContact(int index) {

	std::cout << "\nContact N˚: " << index + 1 << "\n" << std::endl;
	std::cout << "First name : " \
				<< PhoneBook::_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name : " \
				<< PhoneBook::_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname : " \
				<< PhoneBook::_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number : " \
				<< PhoneBook::_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " \
				<< PhoneBook::_contacts[index].getDarkestSecret() << std::endl;
}

/*7*/

void PhoneBook::exit() {
	std::cout << "Exiting PhoneBook" << std::endl;
}
/* ************************************************************************** */
