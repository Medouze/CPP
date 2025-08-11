#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& hWeapon) : _name(name), _hWeapon(hWeapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << _name << " attack with their " << _hWeapon.getType() << std::endl;
}