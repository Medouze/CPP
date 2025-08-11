#include "Base.hpp"

Base * generate(void){
    int nbr = rand()%3;

    switch(nbr){
        case 0 : 
            return(new A);
        case 1 : 
            return(new B);
        case 2 : 
            return(new C);
        default : 
            return(new A);
    }
}

void identify(Base* p){
    if (dynamic_cast<A *>(p))
        std::cout << "It's A !" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "It's B !" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "It's C !" << std::endl;
    else
        std::cout << "Error" << std::endl;
}

void identify(Base& p){
    try{
        dynamic_cast<A &>(p);
        std::cout << "It's A !" << std::endl;
        return;
    }
    catch(const std::bad_cast& ex){
    }
    try{
        dynamic_cast<B &>(p);
        std::cout << "It's B !" << std::endl;
        return;
    }
    catch(const std::bad_cast& ex){
    }
    try{
        dynamic_cast<C &>(p);
        std::cout << "It's C !" << std::endl;
        return;
    }
    catch(const std::bad_cast& ex){
    }
    std::cout << "Error" << std::endl;
}


int main()
{
    srand (time(NULL));
    Base *test = generate();
    identify(test);
    identify(*test);
    return 0;
}
