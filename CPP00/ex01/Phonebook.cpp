#include "Phonebook.hpp"

Phonebook::Phonebook() : _index(0)
{
}

Phonebook::~Phonebook()
{
}

void Phonebook::add_contact()
{
    system("clear");
    std::cout << "**************************" << std::endl;
    std::cout << "*  CREATE A NEW CONTACT  *" << std::endl;
    std::cout << "**************************" << std::endl;
    if (this->_index == 7)
        this->_index = 0;
    this->_contacts[this->_index].new_contact(this->_index);
    this->_index++;
}

void Phonebook::searchContacts()
{
    std::string choice;
    int nbr;

    system("clear");
    std::cout << "***************************" << std::endl;
    std::cout << "*     LIST OF CONTACT     *" << std::endl;
    std::cout << "***************************" << std::endl << std::endl;
    if (!_contacts[0].contact_exists())
    {
        std::cout << "No contact in list" << std::endl;
        return ;
    }
    for (int i = 0; i < 7; i++)
        _contacts[i].show_infos();
    if (!std::getline(std::cin, choice))
        exit(EXIT_FAILURE);
    nbr = std::atoi(choice.c_str());
    while (choice.empty() || nbr < 0 || nbr > 7 || !_contacts[nbr].contact_exists())
    {
        choice.clear();
        while (choice.empty())
        {
            std::cout << "Choose an index that exists : >";
            if (!std::getline(std::cin, choice))
                exit(EXIT_FAILURE);
        }
        nbr = std::atoi(choice.c_str());
    }
    _contacts[nbr].printContact();
}
