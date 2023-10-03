/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:29:37 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/10/03 11:34:52 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"MateriaSource.hpp"
#include	"Character.hpp"
#include	"Cure.hpp"
#include	"Ice.hpp"

void basicTest() {
    std::cout << "=== Subject's Test ===" << std::endl;
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
	std::cout << std::endl;
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
    me->equip(tmp);

	me->unequip(0);
	me->equip(tmp);

	for(int i=0; i<4; i++) { me->unequip(i); }
    
    delete me;
    delete src;
	std::cout << std::endl;
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
	std::cout << std::endl;
}

void unequipTest() {
    std::cout << "=== Unequip Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    ICharacter* me = new Character("Unequipper");
    me->equip(src->createMateria("ice"));
    me->unequip(0);
    me->use(0, *me);
    
    delete me;
    delete src;
	std::cout << std::endl;
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
	std::cout << std::endl;
}

// Here are no Character present so materia needs to be delted
void learningAndCreationTest() {
    std::cout << "=== Learning and Creation Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    AMateria* iceMateria = src->createMateria("ice");
    std::cout << "Created Materia Type: " << iceMateria->getType() << std::endl;

    AMateria* unknownMateria = src->createMateria("fire");
    if (!unknownMateria) {
        std::cout << "Materia 'fire' is unknown" << std::endl;
    }

    delete iceMateria;
    delete src;
	std::cout << std::endl;
}

void nullMateriaTest() {
    std::cout << "=== Null Materia Test ===" << std::endl;
    ICharacter* me = new Character("NullHandler");

	AMateria* nuller = NULL;

	me->equip(nuller);
    me->unequip(0);
    me->use(0, *me);

    delete me;
	std::cout << std::endl;
}

void	reEquipTest() {
	std::cout << "=== reEquip Test ===" << std::endl;

    ICharacter* hoarder = new Character("hoarder");
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
	AMateria* usedGoods = src->createMateria("ice");

	hoarder->equip(usedGoods);
    hoarder->unequip(0);
    
	ICharacter* scavenger = new Character("scavenger");
	scavenger->equip(usedGoods);
	
	hoarder->use(0, *scavenger);
	scavenger->use(0, *hoarder);
	scavenger->unequip(0);

    delete hoarder;
	delete scavenger;
	delete src;
	std::cout << std::endl;
}

// NOTES
// normally it is responsibility of caller to free the memroy. With this subject,
// it is responsibility of character. That is why if you allocate a materia, you cannot
// free it inside caller funtion (main, etc..) see subject for reference tests.
int main() {
	
    basicTest();
    cloningTest();
    fullInventoryTest();
    unequipTest();
    copyAndAssignmentTest();
    learningAndCreationTest();
    nullMateriaTest();
	reEquipTest();

    return 0;
}