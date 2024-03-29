#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	void setType(std::string const raw);
	std::string getType(void) const;

	virtual void makeSound(void) const;
};

#endif // ANIMAL_HPP
