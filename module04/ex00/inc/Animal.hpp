/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 13:59:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

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

	protected:
		std::string	_type;

	private:
	
};

#endif // !ANIMAL_H
