/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:37:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 13:42:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# define FULL 4

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
	
	public:
		Character();
		Character( Character const & other );
		Character& operator=( Character const & other );
		~Character();

	private:
		AMateria*	inventory;

};

#endif // !CHARACTER_H
