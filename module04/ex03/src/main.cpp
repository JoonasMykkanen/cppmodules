/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:29:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/02 17:32:20 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"MateriaSource.hpp"
#include	"Character.hpp"
#include	"Cure.hpp"
#include	"Ice.hpp"

void basicTest() {
    std::cout << "=== Basic Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("IceKing");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("FirePrince");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void fullInventoryTest() {
    std::cout << "=== Full Inventory Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("InventoryMaster");
    for(int i=0; i<4; i++) {
        AMateria* tmp = src->createMateria("ice");
        me->equip(tmp);
    }
    
    AMateria* tmp = src->createMateria("cure");
    me->equip(tmp); // this should not get equipped as inventory is already full
    
    delete me;
    delete src;
}

void cloningTest() {
    std::cout << "=== Cloning Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* original = src->createMateria("ice");
    AMateria* clone = original->clone();
    
    std::cout << "Original Type: " << original->getType() << std::endl;
    std::cout << "Clone Type: " << clone->getType() << std::endl;
    
    delete original;
    delete clone;
    delete src;
}

void unequipTest() {
    std::cout << "=== Unequip Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    ICharacter* me = new Character("Unequipper");
    me->equip(src->createMateria("ice"));
    me->unequip(0);
    me->use(0, *me); // Nothing should happen
    
    delete me;
    delete src;
}

void copyAndAssignmentTest() {
    std::cout << "=== Copy and Assignment Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    Character* me = new Character("Original");
    me->equip(src->createMateria("ice"));

    Character* copyChar = new Character(*me);
    copyChar->use(0, *me);

    ICharacter* assignedChar = new Character("Assigned");
    *assignedChar = *me;
    assignedChar->use(0, *me);

    delete assignedChar;
    delete copyChar;
    delete me;
    delete src;
}

void learningAndCreationTest() {
    std::cout << "=== Learning and Creation Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    AMateria* iceMateria = src->createMateria("ice");
    std::cout << "Created Materia Type: " << iceMateria->getType() << std::endl;

    AMateria* unknownMateria = src->createMateria("fire");
    if (!unknownMateria) {
        std::cout << "Materia is unknown" << std::endl;
    }

    delete iceMateria;
    delete src;
}

void nullMateriaTest() {
    std::cout << "=== Null Materia Test ===" << std::endl;
    ICharacter* me = new Character("NullHandler");
    me->equip(NULL);
    me->unequip(0);
    me->use(0, *me);

    delete me;
}

void repeatedEquippingTest() {
    std::cout << "=== Repeated Equipping Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    ICharacter* me = new Character("Repeater");
    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp); // Should handle repeated equipping gracefully

    delete me;
    delete src;
}

int main() {
    basicTest();
    cloningTest();
    fullInventoryTest();
    unequipTest();
    copyAndAssignmentTest();
    learningAndCreationTest();
    nullMateriaTest();
    repeatedEquippingTest();

    return 0;
}
