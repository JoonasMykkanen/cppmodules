/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:35:54 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 13:43:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HHP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure();
		Cure( Cure const & other );
		Cure& operator=( Cure const & other );
		~Cure();
};

#endif // !CURE_HP

