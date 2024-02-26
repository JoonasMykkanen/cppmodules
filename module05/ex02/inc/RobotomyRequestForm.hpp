/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:45:56 by jmykkane          #+#    #+#             */
/*   Updated: 2024/02/14 15:05:48 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

# include <ctime>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm ( const std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & other );
		RobotomyRequestForm& operator=( RobotomyRequestForm const & other );
		~RobotomyRequestForm( void );

		virtual void	execute(Bureaucrat const & executor) const override;
	
	private:
		std::string	_target;

};

#endif // !ROBOTOMY_HPP

