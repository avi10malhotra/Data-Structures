#include <iostream>
#include <string>

void largestSubsequence(std::string word, std::string max) {
    char largest = word[0];
    int index = 0;
    if (word.length() == 0) {
        std::cout << max << std::endl;
        return;
    }
    for (int i = 1; i < word.length(); i++) {
        if (word[i] > largest) {
            largest = word[i];
            index = i;
        }
    }
    max.push_back(largest);
    largestSubsequence(word.substr(index + 1), max);
}

int main(void) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        largestSubsequence(word, "");
    }
}