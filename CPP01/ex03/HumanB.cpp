#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_hWeapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attack with their " << (*_hWeapon).getType() << std::endl;
}