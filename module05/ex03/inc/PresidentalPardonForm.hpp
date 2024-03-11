/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:45:56 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/11 13:36:53 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARDON_HPP
# define PARDON_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentalPardonForm : public AForm {
	
	public:
		PresidentalPardonForm( void );
		PresidentalPardonForm ( const std::string target );
		PresidentalPardonForm( PresidentalPardonForm const & other );
		PresidentalPardonForm& operator=( PresidentalPardonForm const & other );
		~PresidentalPardonForm( void );

		virtual void	execute(Bureaucrat const & executor) const override;
	
	private:
		std::string	_target;

};

#endif // !PARDON_HPP

