#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream> 

class BitcoinExchange
{
    private:
        std::map<std::string, double> _prices;
        int isValidDate(const std::string &dateString) const;
        bool isOnlyWhitespace(const std::string& str) const;
    public:
        //Canonical form
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        int loadDataBase(const std::string& csvFile);
        int loadInputFile(const std::string& inputFile);
        double getPrice(const std::string& dateString) const;
};


#endif