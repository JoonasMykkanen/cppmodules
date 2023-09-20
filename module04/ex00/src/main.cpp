/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 13:58:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main( void ) {
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Animal type: " << meta->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Cat object:" << std::endl;
	cat->makeSound();
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Dog object:" << std::endl;
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Animal object:" << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
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