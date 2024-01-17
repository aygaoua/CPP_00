/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:44 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/17 09:57:56 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <csignal>
#include <iomanip>
#include <cstdio>
#include "Contact.hpp"
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/*--------------------------------CLASS PART--------------------------------*/
class PhoneBook {
private:
    Contact _contacts[8];
    int _nb_contacts;
public:
    PhoneBook();
    void addContact(Contact contact);
    void searchContact(int index);
    int getNbContacts();
    void searchCommand(PhoneBook &phone);
    Contact getContact(int index);
    void exit();
};

/*--------------------------------FUNCTION PART--------------------------------*/

void printWelcome(void);
bool is_number(std::string str);

#endif