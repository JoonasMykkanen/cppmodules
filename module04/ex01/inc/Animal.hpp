/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 22:20:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal {

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const & other );
		Animal& operator=( Animal const & other );
		virtual ~Animal( void );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;

		virtual void	think( std::string tought ) = 0;
		virtual void	speak( void ) = 0;
		
	protected:
		std::string	_type;
};

#endif // !ANIMAL_H
