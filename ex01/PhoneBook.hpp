/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:44 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/09 15:17:02 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {
public:
    void printWelcome();
    void addContact(Contact contact);
    Contact getContact(int index);
    int getNbContacts();
    void searchContact(int index);
    void printContactField(std::string field);
    void exit();
private:
    Contact _contacts[8];
    int _nb_contacts;
};

#endif