#include "Phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::string input;

    std::cout << "Welcome to your phonebook" << std::endl;
    while (1) 
    {
        std::cout << "*****************" << std::endl;
        std::cout << "*   Main menu   *" << std::endl;
        std::cout << "*****************" << std::endl;
        std::cout << std::endl;
        std::cout << "ADD, SEARCH, EXIT" << std::endl << std::endl;
        std::cout << "> ";
        if (!std::getline(std::cin, input))
            break;    
        if (!input.compare("ADD"))
            phonebook.add_contact();
        else if (!input.compare("SEARCH"))
            phonebook.searchContacts();
        else if (!input.compare("EXIT"))
            break;
        else {
            system("clear");
            std::cout << '[' << input << ']' << " is a bad input !" << std::endl;
        }
    }
}
