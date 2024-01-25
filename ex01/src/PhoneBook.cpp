/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:05:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/25 14:00:20 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook () {
    this->_index = 0;
    this->_amount = 0;
    // std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook () {
    // std::cout << "Phonebook destroyed" << std::endl;
}

std::string PhoneBook::getInput (std::string input) {
    std::string output;

    std::cout << input << ": ";
    std::getline(std::cin, output);
    if (output.length() == 0)
    {
        std::cout << "Input can't be empty!" << std::endl;
        return (this->getInput(input));
    }
    return (output);
}

void PhoneBook::addPreFilledContact (Contact contact) {
    if (this->_amount == 8)
    {
        std::cout << "Phonebook is full, removing oldest contact!" << std::endl;
        for (int i = 0 ; i < 7; i++)
            this->_contacts[i] = this->_contacts[i + 1];
    }
    else
        this->_amount++;
    this->_contacts[this->_amount - 1] = contact;
}

void PhoneBook::addContact () {
    if (this->_amount == 8)
    {
        std::cout << "Phonebook is full, removing oldest contact!" << std::endl;
        for (int i = 0 ; i < 7; i++)
            this->_contacts[i] = this->_contacts[i + 1];
    }
    else
        this->_amount++;
    std::cout << "Add contact at index: " << this->_amount - 1 << std::endl;
    this->_contacts[this->_amount - 1].setFirstName(this->getInput("First name"));
    this->_contacts[this->_amount - 1].setLastName(this->getInput("Last name"));
    this->_contacts[this->_amount - 1].setNickname(this->getInput("Nickname"));
    this->_contacts[this->_amount - 1].setPhoneNumber(this->getInput("Phone number"));
    this->_contacts[this->_amount - 1].setDarkestSecret(this->getInput("Darkest secret"));
}

void PhoneBook::printContact (int index) {
    std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

std::string ShortName(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::searchContact () {

    if (this->_amount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < this->_amount; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << ShortName(this->_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << ShortName(this->_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << ShortName(this->_contacts[i].getNickname()) << std::endl;
    }

    std::string input = this->getInput("Enter index of contact");
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
        this->printContact(input[0] - '0');
    else
        std::cout << "Invalid index!" << std::endl;
}
