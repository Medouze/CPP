#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _prices(other._prices){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other)
        _prices = other._prices;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){}

int    BitcoinExchange::loadDataBase(const std::string& csvFile){
    std::ifstream file(csvFile.c_str());
    if (!file.is_open()){
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }

    std::string line;
    while (getline(file, line)){
        size_t pos = line.find(',');
        if (pos != std::string::npos){
            std::string dateString = line.substr(0, pos);
            std::string priceString = line.substr(pos + 1);

            //Convert second string to double
            std::stringstream ss(priceString);
            double price;
            if (ss >> price)
                _prices[dateString] = price;
        }
    }
    file.close();
    return 1;
}

int BitcoinExchange::isValidDate(const std::string &dateString) const{
    size_t pos = dateString.find('-');
    if (pos == std::string::npos)
        return 0;
    std::string year = dateString.substr(0, pos);
    std::string remain = dateString.substr(pos + 1);
    size_t pos2 = remain.find('-');
    if (pos2 == std::string::npos)
            return 0;
    std::string month = remain.substr(0, pos2);
    std::string day = remain.substr(pos2 + 1);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        return 0;
    int y,m,d;
    std::stringstream ss1(year), ss2(month), ss3(day);
    if (!(ss1 >> y) || !(ss2 >> m) || !(ss3 >> d))
        return 0;
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return 0;
    return 1;
}

double BitcoinExchange::getPrice(const std::string& dateString) const {
    std::map<std::string, double>::const_iterator it = _prices.find(dateString);
    if (it != _prices.end()) {
        return it->second;
    }
    
    // Sinon cherche closest
    std::string closestDate = "";
    for (it = _prices.begin(); it != _prices.end(); ++it) {
        if (it->first <= dateString) {
            closestDate = it->first;
        } else {
            break;
        }
    }
    
    if (!closestDate.empty()) {
        return _prices.find(closestDate)->second;
    }
    return 0.0;
}

bool BitcoinExchange::isOnlyWhitespace(const std::string& str) const{
    return str.find_first_not_of(" \t\n\r") == std::string::npos;
}

int    BitcoinExchange::loadInputFile(const std::string& inputFile){
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()){
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }

    std::string line;
    std::getline(file, line);

    while (getline(file, line)){
        if (line.empty() || isOnlyWhitespace(line))
            continue ;
        size_t pos = line.find('|');
        if (pos == std::string::npos){
            std::cout << "Error: bad input" << " => " << line << std::endl;
            continue ;
        }
        std::string dateString = line.substr(0, pos);
        std::string priceString = line.substr(pos + 1);
        dateString.erase(0, dateString.find_first_not_of(" \t"));
        dateString.erase(dateString.find_last_not_of(" \t") + 1);
        priceString.erase(0, priceString.find_first_not_of(" \t"));
        priceString.erase(priceString.find_last_not_of(" \t") + 1);

        if (!isValidDate(dateString)){
            std::cout << "Error: bad input" << " => " << dateString << std::endl;
            continue ;
        }

        //Convert second string to double
        std::stringstream ss(priceString);
        double price;
        if (!(ss >> price)){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (price < 0){
            std::cout << "Error: not a positive number" << std::endl;
            continue;
        }
        if (price > 1000){
            std::cout << "Error: too large a number" << std::endl;
            continue;
        }
        //Print value * price
        double bitcoinPrice = getPrice(dateString);
        double finalValue = bitcoinPrice * price;
        std::cout << dateString << " => " << price << " = " << finalValue << std::endl;
    }
    file.close();
    return 1;
}