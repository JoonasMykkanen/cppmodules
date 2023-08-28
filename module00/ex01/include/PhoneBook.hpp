/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:44 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/28 13:57:33 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define LAST_ITEM 40
# define LENGTH 9
# define WIDTH 10

# include "Contact.hpp"
# include <iostream>
# include <sstream>


class PhoneBook {
	public:

		void	addContact( void );
		void	findContact( void );

		PhoneBook( void );
		~PhoneBook( void );
	
	private:
		Contact contacts[8];
};

#endif // !PHONEBOOK_CLASS_H
