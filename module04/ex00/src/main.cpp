/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/01 09:21:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main( void ) {

	std::cout << "Testing constructors" << std::endl;
	Animal	a;
	Dog 	b;
	a = b;
	Cat		d;
	Animal	c(d);
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Animal type: " << meta->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Cat (animal) object:" << std::endl;
	cat->makeSound();
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Dog (animal) object:" << std::endl;
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "Calling makeSound() from Animal (animal) object:" << std::endl;
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
	const WrongCat*  wrong_but_correct_cat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Calling makeSound() from WrongAnimal (animal) object:" << std::endl;
	w_meta->makeSound();
	std::cout << std::endl << "Calling makeSound() from WrongCat (animal) object:" << std::endl;
	w_cat->makeSound();
	std::cout << std::endl << "Calling makeSound() from WrongCat (WrongCat) object:" << std::endl;
	wrong_but_correct_cat->makeSound();
	std::cout << std::endl;

	delete wrong_but_correct_cat;
	delete w_meta;
	delete w_cat;
	
	return 0;
}