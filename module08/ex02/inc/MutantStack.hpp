/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:34:23 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 22:52:23 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
# define MUTANT_HPP

# include <stack>
// # include <iterator>

template <class Type>
class MutantStack : public std::stack<Type> {

	public:
		MutantStack( void ) {};
		MutantStack(const MutantStack &other) { (void)other; };
		MutantStack &operator=(const MutantStack &other) { (void)other; };
		~MutantStack( void ) {};

		typedef typename std::stack<Type>::container_type::iterator iterator;
		typedef typename std::stack<Type>::container_type::const_iterator const_iterator;
		iterator begin() {
			return(std::stack<Type>::c.begin());
		}
		iterator end() {
			return(std::stack<Type>::c.end());
		}
		const_iterator begin() const {
			return(std::stack<Type>::c.begin());
		}
		const_iterator end() const {
			return(std::stack<Type>::c.end());
		}
		
	private:
		
};

#endif // !MUTANT_HPP