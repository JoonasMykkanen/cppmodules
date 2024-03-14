/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:39 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 19:07:55 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <type_traits>
# include <algorithm>
# include <exception>
# include <stdexcept>
# include <climits>
# include <vector>

class Span {
	
	public:
		Span( void );
		Span( unsigned int n );
		Span( Span const & other );
		Span& operator=( Span const & other );
		~Span( void );

		void	addNumber( int num );
		void	addNumbers( std::vector<int> const & nums );

		size_t	shortestSpan( void );
		size_t	longestSpan( void );

	private:
		std::vector<int>	_vec;
		size_t				_maxSize;
		bool				_isSorted;
	
};

#endif // !SPAN_HPP
