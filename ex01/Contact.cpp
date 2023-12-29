/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:19:41 by azgaoua           #+#    #+#             */
/*   Updated: 2023/12/29 01:44:56 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    std::cout << "Contact created" << std::endl;
}

void Contact::setFirstName(std::string first_name) {
    this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name) {
    this->_last_name = last_name;
}

void Contact::setNickname(std::string nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
    this->_phone_number = phone_number;
}

void Contact::setDakestSecret(std::string darkest_secret) {
    this->_dakest_secret = darkest_secret;
}

Contact::~Contact() {
    std::cout << "Contact destroyed" << std::endl;
}

// int main() {
//     Contact contact;
//     return 0;
// }