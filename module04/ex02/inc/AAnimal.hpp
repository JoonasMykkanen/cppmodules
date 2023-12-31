/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 12:21:59 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include "Brain.hpp"
# include <iostream>
# include <string>

class AAnimal {

	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( AAnimal const & other );
		AAnimal& operator=( AAnimal const & other );
		virtual ~AAnimal( void );

		std::string		getType( void ) const;
		virtual void	speak( void ) = 0;
		virtual void	makeSound( void ) const = 0;
		virtual void	think( std::string tought ) = 0;
		
	protected:
		std::string	_type;
};

#endif // !ANIMAL_H
