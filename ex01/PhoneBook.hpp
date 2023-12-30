/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:44 by azgaoua           #+#    #+#             */
/*   Updated: 2023/12/29 06:20:51 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    // int _nb_contacts;
public:
    PhoneBook();
    ~PhoneBook();
    void printWelcome();
    void addContact(Contact contact);
    void getContact(int index);
    void searchContact(int index);
    void printContact(Contact contact);
    void printContactField(std::string field);
    void exit();
};

#endif