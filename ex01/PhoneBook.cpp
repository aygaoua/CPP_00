/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:17:06 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/12 06:21:40 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::printWelcome() {
    std::cout << "                                   ------->> Welcome to the PhoneBook <<-------" << std::endl;
}

void PhoneBook::addContact(Contact contact) {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    static int _nbContacts = 1;

    while (first_name == "")
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first_name);
        if (first_name == "")
            std::cout << "Invalid first name" << std::endl;
    }
    contact.setFirstName(first_name);
    while (last_name == "")
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, last_name);
        if (last_name == "")
            std::cout << "Invalid last name" << std::endl;
    }
    contact.setLastName(last_name);
    while (nickname == "")
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        if (nickname == "")
            std::cout << "Invalid nickname" << std::endl;
    }
    contact.setNickname(nickname);
    while (phone_number == "")
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone_number);
        if (phone_number == "")
            std::cout << "Invalid phone number" << std::endl;
    }
    contact.setPhoneNumber(phone_number);
    while (darkest_secret == "")
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkest_secret);
        if (darkest_secret == "")
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

int PhoneBook::getNbContacts() {
    return this->_nb_contacts;
}

void PhoneBook::searchCommand(PhoneBook &phone) {
    int index = 0;
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|index:    |first name|last name:|nickname: |" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    for (int i = 0; i < phone.getNbContacts(); i++)
    {
        std::cout << "| " << i + 1 << "        |";
        for (unsigned long j = 0; j <= 8 && phone.getContact(i).getFirstName()[j]; j++)
            std::cout << phone.getContact(i).getFirstName()[j];
        if (phone.getContact(i).getFirstName().length() >= 10)
            std::cout << ".";
        else
        {
            if (phone.getContact(i).getFirstName().length() == 10)
                std::cout << phone.getContact(i).getFirstName()[9];
            for (unsigned long j = 0; j < 10 - phone.getContact(i).getFirstName().length(); j++)
                std::cout << " ";
        }
        std::cout << "|";
        for (unsigned long j = 0; j <= 8 && phone.getContact(i).getLastName()[j]; j++)
            std::cout << phone.getContact(i).getLastName()[j];
        if (phone.getContact(i).getLastName().length() >= 10)
            std::cout << ".";
        else
        {
            if (phone.getContact(i).getLastName().length() == 10)
                std::cout << phone.getContact(i).getLastName()[9];
            for (unsigned long j = 0; j < 10 - phone.getContact(i).getLastName().length(); j++)
                std::cout << " ";
        }
        std::cout << "|";
        for (unsigned long j = 0; j <= 8 && phone.getContact(i).getNickname()[j]; j++)
            std::cout << phone.getContact(i).getNickname()[j];
        if (phone.getContact(i).getNickname().length() >= 10)
            std::cout << ".";
        else
        {
            if (phone.getContact(i).getNickname().length() == 10)
                std::cout << phone.getContact(i).getNickname()[9];
            for (unsigned long j = 0; j < 10 - phone.getContact(i).getNickname().length(); j++)
                std::cout << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
        std::cout << " -------------------------------------------" << std::endl;
    }
    while ((index < 1 || index > 8) || (phone.getContact(index).getFirstName() != "" && phone.getContact(index).getLastName() != "" && phone.getContact(index).getNickname() != "" && phone.getContact(index).getPhoneNumber() != "" && phone.getContact(index).getDarkestSecret() != ""))
    {   
        std::string index_s = "";
        while (index_s == "")
        {
            std::cout << "Enter index: ";
            std::getline(std::cin, index_s);
            if (index_s == "")
                std::cout << "Invalid index" << std::endl;
            continue;
        }
        if (!isdigit(index_s[0]) || index_s.length() != 1)
        {
            std::cout << "Invalid index" << std::endl;
            std::cout << "the range available is from 1 to 8" << std::endl;
            continue;
        }
        index = index_s[0] - '0';
        if (index < 1 || index > 8)
        {
            std::cout << "Invalid index" << std::endl;
            std::cout << "the range available is from 1 to 8" << std::endl;
            continue;
        }
        else if (phone.getContact(index - 1).getFirstName() != "" && phone.getContact(index - 1).getLastName() != "" && phone.getContact(index - 1).getNickname() != "" && phone.getContact(index - 1).getPhoneNumber() != "" && phone.getContact(index - 1).getDarkestSecret() != "")
        {
            std::cout << "first name : " << phone.getContact(index - 1).getFirstName() << std::endl;
            std::cout << "last name : " << phone.getContact(index - 1).getLastName() << std::endl;
            std::cout << "nickname : " << phone.getContact(index - 1).getNickname() << std::endl;
            std::cout << "phone number : " << phone.getContact(index - 1).getPhoneNumber() << std::endl;
            std::cout << "darkest secret : " << phone.getContact(index - 1).getDarkestSecret() << std::endl;
            break;
        }
        else
        {
            std::cout << "No contact at this index" << std::endl;
            break;
        }
    }
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

bool is_number(std::string str) {
    for (unsigned long i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    PhoneBook phone;

    phone.printWelcome();
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
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return (0);
}


