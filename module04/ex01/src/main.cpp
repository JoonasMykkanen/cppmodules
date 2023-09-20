/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 15:38:26 by joonasmykka      ###   ########.fr       */
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
	delete og_dog;
	// Trying to speak the idea from new object
	std::cout << std::endl;
	copy_dog->speak();
	std::cout << std::endl;
	// Shallow copy would also result in double free here
	delete copy_dog;
	std::cout << std::endl;

	std::cout << "Also testing subject's test" << std::endl;
	Dog	basic;
	basic.think("First tought");
	{
		Dog tmp = basic;
	}
	basic.speak();
	
	return 0;
}