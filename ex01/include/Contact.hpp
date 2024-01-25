/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 11:34:47 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/25 13:52:32 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact ();
		~Contact ();

		std::string getFirstName ();
		std::string getLastName ();
		std::string getNickname ();
		std::string getPhoneNumber ();
		std::string getDarkestSecret ();

		void setFirstName (std::string firstName);
		void setLastName (std::string lastName);
		void setNickname (std::string nickname);
		void setPhoneNumber (std::string phoneNumber);
		void setDarkestSecret (std::string darkestSecret);
};

#endif