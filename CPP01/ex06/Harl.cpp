#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl; 
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
    std::cout << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*fptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;

    while (i < 4){
        if (level == levels[i])
            break ;
        i++;
    }

    switch (i){
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*fptr[0])();
			std::cout << "[ INFO ]" << std::endl;
			(this->*fptr[1])();
			std::cout << "[ WARNING ]" << std::endl;
			(this->*fptr[2])();
			std::cout << "[ ERROR ]" << std::endl;
			(this->*fptr[3])();
			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*fptr[1])();
			std::cout << "[ WARNING ]" << std::endl;
			(this->*fptr[2])();
			std::cout << "[ ERROR ]" << std::endl;
			(this->*fptr[3])();
			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*fptr[2])();
			std::cout << "[ ERROR ]" << std::endl;
			(this->*fptr[3])();
			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*fptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}


Harl::Harl()
{
}

Harl::~Harl()
{
}
