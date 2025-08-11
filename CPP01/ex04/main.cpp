#include <iostream>
#include <fstream>
#include <string>

std::string customReplace(const std::string& text, const std::string& from, const std::string& to) 
{
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = text.find(from, start)) != std::string::npos) 
	{
        result += text.substr(start, pos - start);
        result += to;
        start = pos + from.length();
    }
    result += text.substr(start);
    return result;
}

int main(int argc, char const *argv[])
{
	if (argc == 4)
	{
		std::ifstream infile(argv[1]);
		if (!infile)
		{
			std::cerr << "Couldn't open file" << std::endl;
			return 1;
		}
		std::ofstream outfile("outfile.txt");
		if (!outfile){
			std::cerr << "Couldn't create output file" << std::endl;
			return 1;
		}
		std::string line;
		while (std::getline(infile, line))
			outfile << customReplace(line, argv[2], argv[3]) << std::endl;
	}
	else
		std::cout << "Parameters should be : filename , str1, str2" << std::endl;
	return 0;
}
