#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testBasicFunctionality() {
    std::cout << "=== TEST BASIC FUNCTIONALITY ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Final size: " << mstack.size() << std::endl;
    
    // Test des itérateurs
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Parcours avec itérateurs:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Conversion vers std::stack
    std::stack<int> s(mstack);
    std::cout << "Stack copiée - size: " << s.size() << ", top: " << s.top() << std::endl;
    
    std::cout << std::endl;
}

void testCanonicalForm() {
    std::cout << "=== TEST CANONICAL FORM ===" << std::endl;
    
    // Test constructeur par défaut
    MutantStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    
    // Test constructeur de copie
    MutantStack<int> stack2(stack1);
    std::cout << "Stack2 (copie de stack1) - size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
    
    // Test opérateur d'assignation
    MutantStack<int> stack3;
    stack3.push(99);
    std::cout << "Stack3 avant assignation - size: " << stack3.size() << ", top: " << stack3.top() << std::endl;
    
    stack3 = stack1;
    std::cout << "Stack3 après assignation - size: " << stack3.size() << ", top: " << stack3.top() << std::endl;
    
    // Vérification que les copies sont indépendantes
    stack1.push(42);
    std::cout << "Après push(42) sur stack1:" << std::endl;
    std::cout << "Stack1 - size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
    std::cout << "Stack2 - size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
    std::cout << "Stack3 - size: " << stack3.size() << ", top: " << stack3.top() << std::endl;
    
    std::cout << std::endl;
}

void testIterators() {
    std::cout << "=== TEST ITERATORS ===" << std::endl;
    
    MutantStack<std::string> strStack;
    strStack.push("premier");
    strStack.push("deuxieme");
    strStack.push("troisieme");
    strStack.push("quatrieme");
    
    std::cout << "Forward iterator:" << std::endl;
    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse iterator:" << std::endl;
    for (MutantStack<std::string>::reverse_iterator it = strStack.rbegin(); it != strStack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test const iterators
    const MutantStack<std::string> constStack(strStack);
    std::cout << "Const iterator:" << std::endl;
    for (MutantStack<std::string>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void compareWithList() {
    std::cout << "=== COMPARISON WITH STD::LIST ===" << std::endl;
    
    std::cout << "--- MutantStack output ---" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "--- std::list output ---" << std::endl;
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator it2 = lst.begin();
    std::list<int>::iterator ite2 = lst.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    
    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== TEST EDGE CASES ===" << std::endl;
    
    // Stack vide
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    std::cout << "Empty stack begin == end: " << (emptyStack.begin() == emptyStack.end()) << std::endl;
    
    // Un seul élément
    MutantStack<int> singleStack;
    singleStack.push(42);
    std::cout << "Single element stack:" << std::endl;
    for (MutantStack<int>::iterator it = singleStack.begin(); it != singleStack.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    // Auto-assignation
    MutantStack<int> selfAssignStack;
    selfAssignStack.push(1);
    selfAssignStack.push(2);
    selfAssignStack = selfAssignStack;  // Auto-assignation
    std::cout << "Self-assignment - size: " << selfAssignStack.size() << ", top: " << selfAssignStack.top() << std::endl;
    
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testCanonicalForm();
    testIterators();
    compareWithList();
    testEdgeCases();
    
    std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}