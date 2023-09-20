/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:52:38 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 15:25:02 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal {

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const & other );
		WrongAnimal& operator=( WrongAnimal const & other );
		virtual ~WrongAnimal( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;

	protected:
		std::string	_type;

	private:
	
};

#endif // !WRONGANIMAL_H
