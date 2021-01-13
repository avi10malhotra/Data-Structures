#include <iostream>
#include <string>
#include <sstream>
#include <map>
int main(void) {
    std::map<std::string, int> wordCount;
    std::string str;
    while (std::getline(std::cin, str) && str.length() != 0) {
        std::stringstream ss(str);
        std::string word;
        while (ss >> word)
            wordCount[word]++;
    }

    std::map<std::string, int>::iterator i;
    for (i = wordCount.begin(); i != wordCount.end(); i++)
        std::cout << i->first << " " << i->second << std::endl;
}