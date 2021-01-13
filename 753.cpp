#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    string str;
    while (getline(cin, str)) {
        int ans = 0;
        vector<int> weights;
        weights.reserve((int)str.length());
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                weights.emplace_back(i);
            else {
                ans ^= ((i + 1 - weights.back()) / 2);
                weights.pop_back();
            }
        }
        cout << ans << endl;
    }
}