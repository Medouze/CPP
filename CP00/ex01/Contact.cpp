#include "Contact.hpp"

Contact::Contact() : _index(-1)
{
}

Contact::~Contact()
{
}

void Contact::new_contact(int index)
{
    _index = index;
    this->_ask_info(_first_name, "First name : ");
    this->_ask_info(_last_name, "Name : ");
    this->_ask_info(_nickname, "Nickname : ");
    this->_ask_info(_phone_number, "Phone number : ");
    this->_ask_info(_darkest_secret, "Dark secret : ");
}
void Contact::_ask_info(std::string& info, std::string const title)
{
    info.clear();
    while (info.empty())
    {
        std::cout << title;
        if (!std::getline(std::cin, info))
            exit(EXIT_FAILURE);
        if (info == _first_name || info == _last_name)
        {
            for (int i = 0; i < (int)info.length(); i++)
            {
                if (!isalpha(info[i]))
                    info.clear();
            }
        }
        if (info == _phone_number)
        {
            for (int i = 0; i < (int)info.length(); i++)
            {
                if (isalpha(info[i]))
                    info.clear();
            }
        }
    }
}

void    Contact::show_infos() const
{
    if (_first_name.empty())
    {
        std::cout << "          |";
        std::cout << "          |";
        std::cout << "          |";
        std::cout << "          |" << std::endl;
    }
    else
    {
        std::cout << "         " << _index;
        std::cout << "|";
        std::cout << _fix10Char(_first_name);
        std::cout << "|";
        std::cout << _fix10Char(_last_name);
        std::cout << "|";
        std::cout << _fix10Char(_nickname);
        std::cout << "|";
        std::cout << std::endl;
    }
}

std::string Contact::_fix10Char(std::string str) const
{
    std::string newStr(10, 32);
    if (str.length() > 10)
    {
        newStr = str.substr(0, 9);
        newStr.append(".");
    }
    else
    {
        int size = str.length();
        newStr = newStr.substr(0, 10 - size);
        newStr.append(str);
    }
    return newStr;
}

void Contact::printContact() const
{
    system("clear");
    std::string    input;

    std::cout << "Firstname : " << this->_first_name << std::endl;
    std::cout << "Lastname : " << this->_last_name << std::endl;
    std::cout << "Nickname : " << this->_nickname << std::endl;
    std::cout << "Phone number : " << this->_phone_number << std::endl;
    std::cout << "Darkest secret : " << this->_darkest_secret << std::endl;
    std::cout << std::endl << "Press [ENTER] to continue..." << std::endl;
    if (!std::getline(std::cin, input))
        exit(EXIT_SUCCESS);
    system("clear");
}

bool Contact::contact_exists() const
{
    return(!_first_name.empty());
}