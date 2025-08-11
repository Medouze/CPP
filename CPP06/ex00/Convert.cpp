#include "Convert.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// Helper function to detect the type of literal
ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal) {
    if (literal.empty()) return INVALID;
    
    // Check for char literal: 'c'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return CHAR_LITERAL;
    }
    
    // Check for special float values
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        return FLOAT_LITERAL;
    }
    
    // Check for special double values
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        return DOUBLE_LITERAL;
    }
    
    // Check for float literal (ends with 'f')
    if (literal.length() > 1 && literal[literal.length() - 1] == 'f') {
        std::string withoutF = literal.substr(0, literal.length() - 1);
        if (isValidNumber(withoutF)) {
            return FLOAT_LITERAL;
        }
    }
    
    // Check for double literal (contains decimal point)
    if (literal.find('.') != std::string::npos) {
        if (isValidNumber(literal)) {
            return DOUBLE_LITERAL;
        }
    }
    
    // Check for int literal
    if (isValidInteger(literal)) {
        return INT_LITERAL;
    }
    
    return INVALID;
}

// Helper function to check if string is a valid number
bool ScalarConverter::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    bool hasDecimal = false;
    for (size_t i = start; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Helper function to check if string is a valid integer
bool ScalarConverter::isValidInteger(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Helper function to check if char is displayable
bool ScalarConverter::isDisplayable(char c) {
    return (c >= 32 && c <= 126);
}

// Helper function to safely convert string to long long
bool ScalarConverter::stringToLongLong(const std::string& str, long long& result) {
    std::istringstream iss(str);
    iss >> result;
    return !iss.fail() && iss.eof();
}

// Main conversion function
void ScalarConverter::convert(const std::string& literal) {
    LiteralType type = detectType(literal);
    
    if (type == INVALID) {
        std::cout << "Error: Invalid literal format" << std::endl;
        return;
    }
    
    // Variables to store converted values
    char charValue = 0;
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;
    
    // Flags to track conversion possibilities
    bool charPossible = true;
    bool intPossible = true;
    bool floatPossible = true;
    bool doublePossible = true;
    
    // Convert based on detected type
    switch (type) {
        case CHAR_LITERAL: {
            charValue = literal[1];
            intValue = static_cast<int>(charValue);
            floatValue = static_cast<float>(charValue);
            doubleValue = static_cast<double>(charValue);
            break;
        }
        
        case INT_LITERAL: {
            long long temp;
            if (stringToLongLong(literal, temp)) {
                // Check if it fits in int
                if (temp > std::numeric_limits<int>::max() || 
                    temp < std::numeric_limits<int>::min()) {
                    intPossible = false;
                } else {
                    intValue = static_cast<int>(temp);
                }
                
                // Check if it fits in char
                if (temp > std::numeric_limits<char>::max() || 
                    temp < std::numeric_limits<char>::min()) {
                    charPossible = false;
                } else {
                    charValue = static_cast<char>(temp);
                }
                
                floatValue = static_cast<float>(temp);
                doubleValue = static_cast<double>(temp);
            } else {
                charPossible = intPossible = floatPossible = doublePossible = false;
            }
            break;
        }
        
        case FLOAT_LITERAL: {
            if (literal == "nanf") {
                floatValue = std::numeric_limits<float>::quiet_NaN();
                charPossible = intPossible = false;
            } else if (literal == "+inff") {
                floatValue = std::numeric_limits<float>::infinity();
                charPossible = intPossible = false;
            } else if (literal == "-inff") {
                floatValue = -std::numeric_limits<float>::infinity();
                charPossible = intPossible = false;
            } else {
                std::string withoutF = literal.substr(0, literal.length() - 1);
                std::istringstream iss(withoutF);
                iss >> floatValue;
                if (!iss.fail() && iss.eof()) {
                    // Check if it fits in char
                    if (floatValue > std::numeric_limits<char>::max() || 
                        floatValue < std::numeric_limits<char>::min() || 
                        std::isnan(floatValue) || std::isinf(floatValue)) {
                        charPossible = false;
                    } else {
                        charValue = static_cast<char>(floatValue);
                    }
                    
                    // Check if it fits in int
                    if (floatValue > std::numeric_limits<int>::max() || 
                        floatValue < std::numeric_limits<int>::min() || 
                        std::isnan(floatValue) || std::isinf(floatValue)) {
                        intPossible = false;
                    } else {
                        intValue = static_cast<int>(floatValue);
                    }
                } else {
                    charPossible = intPossible = floatPossible = false;
                }
            }
            doubleValue = static_cast<double>(floatValue);
            break;
        }
        
        case DOUBLE_LITERAL: {
            if (literal == "nan") {
                doubleValue = std::numeric_limits<double>::quiet_NaN();
                charPossible = intPossible = false;
            } else if (literal == "+inf") {
                doubleValue = std::numeric_limits<double>::infinity();
                charPossible = intPossible = false;
            } else if (literal == "-inf") {
                doubleValue = -std::numeric_limits<double>::infinity();
                charPossible = intPossible = false;
            } else {
                std::istringstream iss(literal);
                iss >> doubleValue;
                if (!iss.fail() && iss.eof()) {
                    // Check if it fits in char
                    if (doubleValue > std::numeric_limits<char>::max() || 
                        doubleValue < std::numeric_limits<char>::min() || 
                        std::isnan(doubleValue) || std::isinf(doubleValue)) {
                        charPossible = false;
                    } else {
                        charValue = static_cast<char>(doubleValue);
                    }
                    
                    // Check if it fits in int
                    if (doubleValue > std::numeric_limits<int>::max() || 
                        doubleValue < std::numeric_limits<int>::min() || 
                        std::isnan(doubleValue) || std::isinf(doubleValue)) {
                        intPossible = false;
                    } else {
                        intValue = static_cast<int>(doubleValue);
                    }
                } else {
                    charPossible = intPossible = doublePossible = false;
                }
            }
            floatValue = static_cast<float>(doubleValue);
            break;
        }
        
        case INVALID:
            // Should not reach here due to early return
            break;
    }
    
    // Display results
    std::cout << std::fixed << std::setprecision(1);
    
    // Char output
    std::cout << "char: ";
    if (!charPossible) {
        std::cout << "impossible";
    } else if (!isDisplayable(charValue)) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << charValue << "'";
    }
    std::cout << std::endl;
    
    // Int output
    std::cout << "int: ";
    if (!intPossible) {
        std::cout << "impossible";
    } else {
        std::cout << intValue;
    }
    std::cout << std::endl;
    
    // Float output
    std::cout << "float: ";
    if (!floatPossible) {
        std::cout << "impossible";
    } else if (std::isnan(floatValue)) {
        std::cout << "nanf";
    } else if (std::isinf(floatValue)) {
        std::cout << (floatValue > 0 ? "+inff" : "-inff");
    } else {
        std::cout << floatValue << "f";
    }
    std::cout << std::endl;
    
    // Double output
    std::cout << "double: ";
    if (!doublePossible) {
        std::cout << "impossible";
    } else if (std::isnan(doubleValue)) {
        std::cout << "nan";
    } else if (std::isinf(doubleValue)) {
        std::cout << (doubleValue > 0 ? "+inf" : "-inf");
    } else {
        std::cout << doubleValue;
    }
    std::cout << std::endl;
}