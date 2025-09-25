#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::string str;
    public:
        //Cannonical form
        RPN();
        RPN(int argc, char** argv);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        //Helpers
        int validStr();
        void printStack(std::stack<int> s) const;

        //Final operation
        void operation();

        //Setter
        void setStr(std::string str);
};

#endif
