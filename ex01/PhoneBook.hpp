/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:44 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/12 05:46:35 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {
private:
    Contact _contacts[8];
    int _nb_contacts;
public:
    PhoneBook() : _nb_contacts(0) {};
    void printWelcome();
    void addContact(Contact contact);
    void searchContact(int index);
    void printContactField(std::string field);
    int getNbContacts();
    void searchCommand(PhoneBook &phone);
    Contact getContact(int index);
    void exit();
};

#endif