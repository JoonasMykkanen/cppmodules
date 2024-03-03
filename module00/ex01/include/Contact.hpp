/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:24:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/12 08:20:21 by joonasmykka      ###   ########.fr       */
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
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_number;
		std::string _secret;
		bool		_filled;
		int			_index;

		static int	_nbInst;
		
};

#endif // !CONTACT_CLASS_H