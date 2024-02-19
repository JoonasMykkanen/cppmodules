/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:57:41 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/19 07:44:32 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "./PresidentalPardonForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./AForm.hpp"
# include <string>

class Intern {

	class UnknownFormException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};

	public:
		Intern( void );
		Intern( Intern const & other );
		Intern& operator=( Intern const & other );
		~Intern( void );

		AForm*	makeForm( std::string const formName, std::string const targetName );
	
	private:
		typedef AForm*	(Intern::*t_forms[])(std::string);
		AForm*	makeRobotomy( std::string target );
		AForm*	makeShrubbery( std::string target );
		AForm*	makePresidental( std::string target );

};

#endif // !INTERN_HPP