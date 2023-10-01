/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 13:07:52 by joonasmykka      ###   ########.fr       */
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
		// ~Animal( void ); // TO TEST ERROR WITHOUT VIRTUAL KEYWORD
		// btw compiler will catch this error, you'll need to remove -Werror flag to turn it to warnings only

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
		
	protected:
		std::string	_type;
};

#endif // !ANIMAL_H
