/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:15:08 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/11 13:36:28 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <ostream>
# include <string>

class Bureaucrat;

class AForm
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

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
	
		AForm( void );
		AForm ( const std::string name, const int signGrade, const int execGrade);
		AForm( AForm const & other );
		AForm& operator=( AForm const & other );
		virtual ~AForm( void ) = 0;

		// Getters
		std::string const &	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		// Setterss
		void				setSigned( bool status );
		
		// Other class methods
		void				beSigned( Bureaucrat const & user );
		virtual void 		execute( Bureaucrat const & executor ) const;

	private: 
	
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int	const			_execGrade;

};

std::ostream& operator<<( std::ostream& os, AForm const & obj );

#endif // !AFORM_HPP
