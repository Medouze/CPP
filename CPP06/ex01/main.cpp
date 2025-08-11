

#include "Serialize.hpp"

int main()
{
    Data *test = new Data;
    test->id = 4;
    test->value = 4.5;
    test->name = "hello";

    std::cout << test->id << std::endl;
    std::cout << test->value << std::endl;
    std::cout << test->name << std::endl;

    uintptr_t x = Serialize::serialize(test);
    Data *y = Serialize::deserialize(x);

    std::cout << y->id << std::endl;
    std::cout << y->value << std::endl;
    std::cout << y->name << std::endl;
    return 0;
}
