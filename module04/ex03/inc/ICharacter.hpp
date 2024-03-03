/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:37:36 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 07:13:37 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H
 
#include <string>

class AMateria;


class ICharacter {
	public:
		virtual	~ICharacter() {}
		virtual	std::string const & getName() const = 0;
		virtual	void equip(AMateria* m) = 0;
		virtual	void unequip(int idx) = 0;
		virtual	void use(int idx, ICharacter& target) = 0;
};

#endif // !ICHARACTER_H
