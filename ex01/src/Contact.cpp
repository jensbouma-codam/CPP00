/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:08:34 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/25 13:58:24 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact () {
    // std::cout << "Contact created" << std::endl;
}

Contact::~Contact () {
    // std::cout << "Contact destroyed" << std::endl;
}

std::string Contact::getFirstName () {
    return (this->_firstName);
}

std::string Contact::getLastName () {
    return (this->_lastName);
}

std::string Contact::getNickname () {
    return (this->_nickname);
}

std::string Contact::getPhoneNumber () {
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret () {
    return (this->_darkestSecret);
}

void Contact::setFirstName (std::string firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName (std::string lastName) {
    this->_lastName = lastName;
}

void Contact::setNickname (std::string nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber (std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret (std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

