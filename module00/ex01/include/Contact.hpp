/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/28 13:11:54 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {
	public:
		Contact( void );
		~Contact( void );

		int			getIndex( void );
		bool		getFilled( void );
		std::string	getSecret( void );
		std::string	getNumber( void );
		std::string	getLastName( void );
		std::string	getNickName( void );
		std::string	getFirstName( void );

		void	setFirstName( std::string var );
		void	setLastName( std::string var );
		void	setNickName( std::string var );
		void	setSecret( std::string var );
		void	setNumber( std::string var );
		void	setFilled( bool var );
		void	setIndex( int var );

		static int	getNbInst( void );
		
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	number;
		std::string secret;
		bool		filled;
		int			index;

		static int	_nbInst;
		
};

#endif // !CONTACT_CLASS_H