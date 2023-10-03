/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 07:30:24 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/03 11:35:42 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define FULL_MEMORY 4

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & other );
		MateriaSource& operator=( MateriaSource const & other );
		~MateriaSource( void );

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);

	private:
		AMateria*	_memory[4];
		int			_index;
};

#endif // !MATERIASOURCE_HPP
