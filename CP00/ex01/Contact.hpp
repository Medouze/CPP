#pragma once
#include <iostream>
#include <cstdlib>

class Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
    int _index;

    void _ask_info(std::string& info, std::string const title);
    std::string _fix10Char(std::string str) const; 
public:
    Contact();
    ~Contact();
    void new_contact(int index);
    void show_infos() const;
    void printContact() const;
    bool contact_exists() const;
};
