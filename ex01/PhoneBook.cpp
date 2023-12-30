/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:17:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/12/30 21:15:36 by azgaoua          ###   ########.fr       */
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

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cout << " ___________________________________________" << std::endl;
            std::cout << "|index:    |first name|last name:|nickname: |" << std::endl;
            for (int i = 0; i < 8; i++)
            {
                std::cout << "| " << i << "        |";
                for (unsigned long j = 0; j <= 9 && phone.getContact(i).getFirstName()[j]; j++)
                    std::cout << phone.getContact(i).getFirstName()[j];
                for (unsigned long j = 0; j < 10 - phone.getContact(i).getFirstName().length(); j++)
                    std::cout << " ";
                std::cout << "|";
                for (unsigned long j = 0; j <= 9 && phone.getContact(i).getLastName()[j]; j++)
                    std::cout << phone.getContact(i).getLastName()[j];
                for (unsigned long j = 0; j < 10 - phone.getContact(i).getLastName().length(); j++)
                    std::cout << " ";
                std::cout << "|";
                for (unsigned long j = 0; j <= 9 && phone.getContact(i).getNickname()[j]; j++)
                    std::cout << phone.getContact(i).getNickname()[j];
                for (unsigned long j = 0; j < 10 - phone.getContact(i).getNickname().length(); j++)
                    std::cout << " ";
                std::cout << "|";
                std::cout << std::endl;
                std::cout << " -------------------------------------------" << std::endl;
            }   
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << " ______________________________________________________" << std::endl;
            std::cout << "|first name|last name:|nickname: |N. phone: |" << std::endl;
            for (unsigned long j = 0; j <= 9 && phone.getContact(index).getFirstName()[j]; j++)
                std::cout << phone.getContact(index).getFirstName()[j];
            for (unsigned long j = 0; j < 10 - phone.getContact(index).getFirstName().length(); j++)
                std::cout << " ";
            std::cout << "|";
            for (unsigned long j = 0; j <= 9 && phone.getContact(index).getLastName()[j]; j++)
                std::cout << phone.getContact(index).getLastName()[j];
            for (unsigned long j = 0; j < 10 - phone.getContact(index).getFirstName().length(); j++)
                std::cout << " ";
            std::cout << "|";
            for (unsigned long j = 0; j <= 9 && phone.getContact(index).getNickname()[j]; j++)
                std::cout << phone.getContact(index).getNickname()[j];
            for (unsigned long j = 0; j < 10 - phone.getContact(index).getNickname().length(); j++)
                std::cout << " ";
            std::cout << "|";
            for (unsigned long j = 0; j <= 9 && phone.getContact(index).getPhoneNumber()[j]; j++)
                std::cout << phone.getContact(index).getPhoneNumber()[j];
            // std::cout << phone.getContact(index).getPhoneNumber();
            for (unsigned long j = 0; j < 10 - phone.getContact(index).getPhoneNumber().length(); j++)
                std::cout << " ";
            std::cout << "|" << std::endl;
            std::cout << " ------------------------------------------------------" << std::endl;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}


