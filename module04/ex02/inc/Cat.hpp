/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:16:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 12:30:29 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat( void );
		Cat( Cat const & other );
		Cat& operator=( Cat const & other );
		~Cat( void );

		// In C++11 there is override keyword that would improve readibility
		// and compile-time checking Example: void	speak( void ) override;
		void	speak( void );
		void	makeSound( void ) const;
		void	think( std::string tought );

	private:
		int		index_;
		Brain*	ideas_;

};

#endif // !CAT_H