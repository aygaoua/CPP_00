/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:17:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/12/29 06:21:59 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    std::cout << "PhoneBook created" << std::endl;
}

void PhoneBook::printWelcome() {
    std::cout << "Welcome to the PhoneBook" << std::endl;
}

void PhoneBook::addContact(Contact contact) {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    static int _nbContacts = 0;

    std::cout << "Enter first name: ";
    std::cin >> first_name;
    contact.setFirstName(first_name);
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    contact.setLastName(last_name);
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    contact.setNickname(nickname);
    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    contact.setPhoneNumber(phone_number);
    std::cout << "Contact added" << std::endl;
    _contacts[_nbContacts] = contact;
    _nbContacts++;
}

void PhoneBook::getContact(int index) {
    std::cout << "Getting contact" << std::endl;
    std::cout << "First name: " << PhoneBook::_contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << PhoneBook::_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << PhoneBook::_contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << PhoneBook::_contacts[index].getPhoneNumber() << std::endl;
}

void PhoneBook::searchContact(int index) {
    std::cout << "Searching contact" << std::endl;

    std::cout << "First name: " << PhoneBook::_contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << PhoneBook::_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << PhoneBook::_contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << PhoneBook::_contacts[index].getPhoneNumber() << std::endl;

}

void PhoneBook::printContact(Contact contact) {
    std::cout << "Printing contact" << std::endl;
}

void PhoneBook::printContactField(std::string field) {
    std::cout << field << std::endl;
}

void PhoneBook::exit() {
    std::cout << "Exiting PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destroyed" << std::endl;
}

int main() {
    PhoneBook phonebook;

    while (1) {
        std::string command;
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "EXIT")
            phonebook.exit();
        else if (command == "ADD")
            phonebook.addContact(Contact());
        else if (command == "SEARCH")
        {
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            phonebook.getContact(index);
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}


