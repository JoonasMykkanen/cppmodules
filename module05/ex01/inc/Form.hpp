/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:15:08 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/26 22:20:23 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form
{
	public:

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
	
		Form( void );
		Form ( const std::string name, const int signGrade, const int execGrade);
		Form( Form const & other );
		Form& operator=( Form const & other );
		~Form( void );

		std::string const &	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( Bureaucrat const & user );

	private:
	
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int	const			_execGrade;

};

std::ostream& operator<<( std::ostream& os, Form const & obj );

#endif // !FORM_HPP
