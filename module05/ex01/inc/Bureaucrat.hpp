/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:31:02 by joonasmykka       #+#    #+#             */
/*   Updated: 2024/02/08 11:42:22 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GRADE_HIGH 1
# define GRADE_LOW 150

# include <iostream>
# include <string>

# include "Form.hpp"

class Form;

class Bureaucrat {
	
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		
		Bureaucrat( void );
		Bureaucrat( std::string const & newName, int newGrade );
		Bureaucrat( Bureaucrat const & other );
		Bureaucrat& operator=( Bureaucrat const & other );
		~Bureaucrat( void );

		std::string const & getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );

		void				signForm( Form& form );

	private:
		std::string	const	_name;
		int					_grade;
};

std::ostream& operator<<( std::ostream& os, Bureaucrat const & obj );

#endif // !BUREAUCRAT_HPP