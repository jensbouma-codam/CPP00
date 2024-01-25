/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 11:34:47 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/25 14:00:20 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>


class PhoneBook {
	
	private:
		int _index;
		int _amount;
		Contact _contacts[8];
	
	public:
		PhoneBook ();
		~PhoneBook ();

		std::string getInput (std::string input);
		
		void addContact ();
		void addPreFilledContact (Contact contact);
		void searchContact ();
		void printContact (int index);
};

#endif