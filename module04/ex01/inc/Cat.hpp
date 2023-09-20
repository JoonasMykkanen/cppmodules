/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:16:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 15:24:13 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat( void );
		Cat( Cat const & other );
		Cat& operator=( Cat const & other );
		~Cat( void );

		void	speak( void );
		void	makeSound( void ) const;
		void	think( std::string tought );

	private:
		int		_index;
		Brain*	_ideas;

};

#endif // !CAT_H