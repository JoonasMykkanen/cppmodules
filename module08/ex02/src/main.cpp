/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:39:47 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/19 11:11:48 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <iterator>

int main( void ) {
	{
		std::cout << std::endl << "--------------- TRYING WITH MUTANTSTACK NOW ---------------" << std::endl;
		MutantStack<int>	mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << "--------------- TRYING WITH LIST NOW ---------------" << std::endl;
		std::list<int>	list;
		
		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		MutantStack<char> stackerson;

		stackerson.push('l');
		stackerson.push('a');
		stackerson.push('u');
		stackerson.push('k');
		stackerson.push('c');
		stackerson.push('b');

		std::cout << "before using sort" << std::endl;
		for (auto it = stackerson.begin(); it != stackerson.end(); ++it) {
			std::cout << " " << *it << " " << std::endl;
		}
		std::cout << std::endl;

		std::cout << "std::sort(stackerson.begin(), stackerson.end());" << std::endl;
		std::sort(stackerson.begin(), stackerson.end());
		std::cout << std::endl;
		
		std::cout << "after using sort" << std::endl;
		for (auto it = stackerson.begin(); it != stackerson.end(); ++it) {
			std::cout << " " << *it << " " << std::endl;
		}
		std::cout << std::endl;
	}


	return 0;
}