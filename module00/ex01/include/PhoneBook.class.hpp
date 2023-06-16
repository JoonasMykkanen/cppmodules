/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:11:44 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/16 14:16:52 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "include/Contact.class.hpp"
# include <iostream>

class PhoneBook {
	public:
		Contact	list[8];

		PhoneBook( void );
		~PhoneBook( void );
	
	private:
		
};

#endif // !PHONEBOOK_CLASS_H
