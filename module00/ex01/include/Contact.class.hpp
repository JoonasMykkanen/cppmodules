/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/16 14:24:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>

class Contact {
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string secret;
		int			index;

		Contact( void );
		~Contact( void );

		static int	getNbInst( void );
		
	private:
		static int	_nbInst;
		
};

#endif // !CONTACT_CLASS_H