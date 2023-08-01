/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 13:29:49 by joonasmykka      ###   ########.fr       */
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
		std::string	type_;

	private:
	
};

#endif // !ANIMAL_H
