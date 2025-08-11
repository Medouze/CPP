#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data {
    int id;
    double value;
    std::string name;
};

class Serialize
{
	private:
		Serialize(void);
		Serialize(Serialize const &other);
		Serialize &operator=(Serialize const &other);
		~Serialize(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif