#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_hWeapon;
public:
	HumanA(std::string name, Weapon& hWeapon);
	~HumanA();
	void	attack();
};

#endif
