/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:35:25 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 14:09:03 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria {
	
	public:
		Ice( void );
		Ice( Ice const & other );
		Ice& operator=( Ice const & other );
		~Ice( void );

		void use(int idx, ICharacter& target);
};

#endif // !ICE_H
