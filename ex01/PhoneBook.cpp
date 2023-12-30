/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:17:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/12/30 18:21:05 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    // std::cout << "PhoneBook created" << std::endl;
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
    std::getline(std::cin, first_name);
    contact.setFirstName(first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    contact.setLastName(last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    contact.setNickname(nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    contact.setPhoneNumber(phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
    contact.setDarkestSecret(darkest_secret);
    std::cout << "Contact " << _nbContacts << " added" << std::endl;
    _nbContacts %= 8;
    if (_nbContacts > this->_nb_contacts)
        this->_nb_contacts = _nbContacts;
    _contacts[_nbContacts] = contact;
    _nbContacts++;
}

Contact PhoneBook::getContact(int index) {
    return this->_contacts[index];
}

void PhoneBook::searchContact(int index) {
    std::cout << "Searching contact" << std::endl;

    std::cout << "First name: " << PhoneBook::_contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << PhoneBook::_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << PhoneBook::_contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << PhoneBook::_contacts[index].getPhoneNumber() << std::endl;

}

void PhoneBook::printContactField(std::string field) {
    std::cout << field << std::endl;
}

void PhoneBook::exit() {
    std::cout << "Exiting PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook() {
    // std::cout << "PhoneBook destroyed" << std::endl;
}

int main() {
    PhoneBook phone;

    while (1) {
        std::string command;
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "EXIT")
            phone.exit();
        else if (command == "ADD")
            phone.addContact(Contact());
        else if (command == "SEARCH")
        {
            int index;
            std::cout << " _____________________________________________________" << std::endl;
            std::cout << "|index: |first name:    |last name:   |nickname:     |" << std::endl;
            for (int i = 0; i < 8; i++)
            {
                std::cout << i << "|";
                std::cout << phone.getContact(i).getFirstName();
                std::cout << "      |";
                std::cout << phone.getContact(i).getLastName();
                std::cout << "      |";
                std::cout << phone.getContact(i).getNickname();
                std::cout << "      |";
                std::cout << phone.getContact(i).getPhoneNumber();
                std::cout << "      |" << std::endl;
            }   
            std::cout << "______________________________________________" << std::endl;

            std::cout << "Enter index: ";
            std::cin >> index;
            phone.getContact(index);

        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}


