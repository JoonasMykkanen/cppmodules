/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:44 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 09:25:50 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define LAST_ITEM 40
# define LENGTH 9
# define WIDTH 10

# include "Contact.hpp"
# include <iostream>


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
