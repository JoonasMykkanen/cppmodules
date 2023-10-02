/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:37:41 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 17:28:04 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# define MAX_INVENTORY 4

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	
	public:
		Character( std::string const & name );
		Character( Character const & other );
		Character& operator=( Character const & other );
		~Character( void );

		std::string const &	getName( void ) const;
		void				equip( AMateria *m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

	private:
		Character( void );
		std::string	_name;
		int			_index;
		AMateria*	_inventory[4];
		
		AMateria* 	_garbage[1000];
    	int 		_garbageIndex;

};

#endif // !CHARACTER_H
