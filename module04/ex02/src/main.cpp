/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:51:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 22:30:27 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main( void ) {
	int			len = 2;
	AAnimal**	animals = new AAnimal*[len];
	
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
	copy_dog->speak();
	// Shallow copy would also result in double free here
	delete copy_dog;
	std::cout << std::endl;
	// Proving deep copy
	Cat* og_cat = new Cat();
	og_cat->think("I think I am a cat");
	// Copying object to another
	Cat *copy_cat = new Cat();
	*copy_cat = *og_cat;
	// Deleting og before using copied one, shallow copy would result in seg fault here
	delete og_cat;
	// Trying to speak the idea from new object
	copy_cat->speak();
	// Shallow copy would also result in double free here
	delete copy_cat;
	std::cout << std::endl;
	
	return 0;
}