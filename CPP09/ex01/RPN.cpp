#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (i > 1) str += " ";
        str += argv[i];
    }
}
RPN::RPN(const RPN& other) : str(other.str){}
RPN& RPN::operator=(const RPN& other){
    if (this != &other)
        str= other.str;
    return (*this);
}
RPN::~RPN(){}

int RPN::validStr(){
    for (unsigned int i = 0; i < str.length(); i++){
        if ((!isdigit(str[i]) && !isspace(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*') || (isdigit(str[i]) && i + 1 < str.length() && isdigit(str[i + 1])))
            return 0;
    }
    return 1;
}

void RPN::printStack(std::stack<int> s) const{  // Pass by value to make a copy
    if (s.empty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void RPN::operation(){
    if (!validStr()){
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::stack<int> RPNStack;
    for (unsigned int i = 0; i < str.length(); i++){
        if (isspace(str[i]))
            continue;
        else if (isdigit(str[i])){
            int nbr = str[i] - '0';
            RPNStack.push(nbr);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            if (RPNStack.size() < 2){
                std::cerr << "Error: need atleast 2 numbers before an operator" << std::endl;
                return ;
            }
            int secondNbr = RPNStack.top();
            RPNStack.pop();
            int firstNbr = RPNStack.top();
            RPNStack.pop();

            int result;
            if (str[i] == '+')
                result = firstNbr + secondNbr;
            else if (str[i] == '-')
                result = firstNbr - secondNbr;
            else if (str[i] == '*')
                result = firstNbr * secondNbr;
            else if (str[i] == '/'){
                if (secondNbr == 0){
                    std::cerr << "Error: division by zero is forbidden" << std::endl;
                    return ;
                }
                result = firstNbr / secondNbr;
            }
            RPNStack.push(result);
        }
    }
    if (RPNStack.size() == 0 || RPNStack.size() > 1){
        std::cerr << "Error: something is wrong inside the expression" << std::endl;
        return ;
    } else
        std::cout << RPNStack.top() << std::endl;
}