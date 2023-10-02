/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:30:46 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 12:29:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class	AMateria {
	
	public:
		AMateria( std::string const & type );
		AMateria( AMateria const & other );
		AMateria& operator=( AMateria const & other );
		virtual ~AMateria( void );

		std::string const & getType() const;

		virtual	AMateria* 	clone() const = 0;
		virtual void		use( ICharacter& target );

	protected:
		std::string	_type;

};

#endif // !AMATERIA_H
