/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 02:24:17 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/17 13:43:37 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	switch (ac) {
		case 1:
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			break;
		default:
			for (int k = 1; k < ac; k++) {
				std::string str(av[k]);
				for (size_t i = 0; i < str.length(); i++)
					str[i] = std::toupper(str[i]);
				std::cout << str;
			}
			std::cout << std::endl;
	}
}