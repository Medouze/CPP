#include "Serialize.hpp"

Serialize::Serialize(void)
{
}

Serialize::Serialize(Serialize const &other)
{
	*this = other;
}


Serialize &Serialize::operator=(Serialize const &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Serialize::~Serialize(void)
{
}

uintptr_t Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}