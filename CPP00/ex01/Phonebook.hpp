// • ADD: save a new contact
// ◦ If the user enters this command, they are prompted to input the information
// of the new contact one field at a time. Once all the fields have been completed,
// add the contact to the phonebook.
// ◦ The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.


#pragma once
#include <iostream>
#include "Contact.hpp"

class Phonebook
{
private:
    Contact _contacts[8];
    int     _index;
    
public:
    
    Phonebook(/* args */);
    ~Phonebook();

    void add_contact();
    void searchContacts();
};


