/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:16:29 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/01 11:23:24 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog( void );
		Dog( Dog const & other );
		Dog& operator=( Dog const & other );
		~Dog( void );

		void	speak( void );
		void	makeSound( void ) const;
		void	think( std::string tought );

	private:
		int		index_;
		Brain*	ideas_;

};

#endif // !DOG_H