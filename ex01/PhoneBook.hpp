/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:44 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/18 14:08:00 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
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
bool valid(std::string str);

#endif