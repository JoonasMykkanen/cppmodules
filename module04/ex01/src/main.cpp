/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/03 09:34:50 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main( void ) {
	int			len = 2;
	Animal**	animals = new Animal*[len];
	
	for (int i = 0; i < len; i++) {
		if (i < len / 2) {
			animals[i] = new Dog();
			std::cout << std::endl;
		} else {
			animals[i] = new Cat();
			std::cout << std::endl;
		}
	}
	for (int i = 0; i < 2; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
	delete[] animals;

	std::cout << std::endl;
	// Proving deep copy
	Dog* og_dog = new Dog();
	og_dog->think("I think I am a dog");
	// Copying object to another
	Dog *copy_dog = new Dog(*og_dog);
	// Deleting og before using copied one, shallow copy would result in seg fault here
	// since it only copied pointer or reference to the allocated memory.
	delete og_dog;
	// Trying to speak the idea from new object
	std::cout << std::endl;
	copy_dog->speak();
	std::cout << std::endl;
	// Shallow copy would also result in double free here since the memory is already freed when og was deleted
	delete copy_dog;
	std::cout << std::endl;

	// With this test if it is not deep copy, tmp will go out of scope and frees its bain.
	// if it's shallow, its the same memory with basic and when basic speaks afterwards
	// it would result in a seg fault.
	std::cout << "Also testing subject's test" << std::endl;
	Dog	basic;
	basic.speak();
	basic.think("First tought");
	{
		Dog test1 = basic;
		Dog	test2(basic);
	}
	basic.speak();

	// test that will cause leaks after removal of virtual destructor keyword.
	std::cout << std::endl;
	std::cout << "This test will fail if no correct implementation of destructors (virtual keyword)\n";
	Animal*	villeveikko = new Dog;
	delete villeveikko;
	std::cout << std::endl;
	
	return 0;
}