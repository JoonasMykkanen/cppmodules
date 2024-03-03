/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:45:56 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/14 15:05:46 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include <fstream>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm ( const std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & other );
		ShrubberyCreationForm& operator=( ShrubberyCreationForm const & other );
		~ShrubberyCreationForm( void );

		virtual void	execute(Bureaucrat const & executor) const override;
	
	private:
		std::string	_target;

};

#endif // !SHRUBBERY_HPP

