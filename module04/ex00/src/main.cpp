/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 13:54:55 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Cat object:" << std::endl;
	i->makeSound();
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Dog object:" << std::endl;
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	std::cout << "Starting tests for wrong --> without polymorphism" << std::endl;
	std::cout << std::endl;
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Calling makeSound() from WrongAnimal object:" << std::endl;
	w_meta->makeSound();
	std::cout << std::endl << "Calling makeSound() from WrongCat object:" << std::endl;
	w_cat->makeSound();
	std::cout << std::endl;

	delete w_meta;
	delete w_cat;
	
	return 0;
}