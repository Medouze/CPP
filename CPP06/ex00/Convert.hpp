#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        
        enum LiteralType {
            CHAR_LITERAL,
            INT_LITERAL,
            FLOAT_LITERAL,
            DOUBLE_LITERAL,
            INVALID
        };
        
        static LiteralType detectType(const std::string& literal);
        static bool isValidNumber(const std::string& str);
        static bool isValidInteger(const std::string& str);
        static bool isDisplayable(char c);
        static bool stringToLongLong(const std::string& str, long long& result);

        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

    public:
        static void convert(const std::string& literal);
};

#endif