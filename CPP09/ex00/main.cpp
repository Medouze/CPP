#include "BitcoinExchange.hpp"

int main(int ac, char **argv) {
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    btc.loadDataBase("data.csv");
    btc.loadInputFile(argv[1]);
    
    return 0;
}
