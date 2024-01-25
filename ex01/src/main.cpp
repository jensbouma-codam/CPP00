/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:17:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/25 14:21:27 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream>
#include <string>
#include <cstring>

void add9 (PhoneBook &phonebook) {
    std::string input;
    std::cout << "Enter amount of random contacts to add: ";
    std::getline(std::cin, input);
    if (input.length() == 0)
    {
        std::cout << "Invalid input!" << std::endl;
        return (add9(phonebook));
    }

    std::cout << "Generate " << std::stoi(input) << " random contacts." << std::endl;
    for (int i = 0; i < std::stoi(input); i++)
    {
        Contact contact;
        std::string url = "curl -L www.pseudorandom.name";
        char buffer[256];
        std::string fullName = "";
        
        FILE *stream = popen(url.c_str(), "r");
        while (fgets(buffer, 256, stream) != NULL)
            fullName = buffer;
        pclose(stream);
        
        fullName.erase(std::remove(fullName.begin(), fullName.end(), '\n'), fullName.end());
        std::string firstName = fullName.substr(0, fullName.find(" "));
        std::string lastName = fullName.substr(fullName.find(" ") + 1, fullName.length());

        contact.setFirstName(firstName);
        contact.setLastName(lastName);
        contact.setNickname(firstName.substr(0, 1) + lastName.substr(0, 1));
        contact.setPhoneNumber("+31" + std::to_string(rand() % 1000000000));
        contact.setDarkestSecret("I'm a random contact without any dark secrets!");
        
        phonebook.addPreFilledContact(contact);
    }
}

int main () {
    PhoneBook phonebook;
    std::string input;

    while (1)
    {
        std::cout << "Enter command: (ADD, RANDOM, SEARCH or EXIT): ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.searchContact();
        else if (input == "RANDOM")
            add9(phonebook);
        else if (input == "EXIT" || !std::cin)
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return (0);
}