/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:35:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 07:02:56 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure( void );
		Cure( Cure const & other );
		Cure& operator=( Cure const & other );
		~Cure( void );

		void 		use( ICharacter& target );
		AMateria*	clone() const;
};

#endif // !CURE_HP

