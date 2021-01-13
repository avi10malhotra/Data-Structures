#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main(void) {
    string str;
    while (getline(cin, str)) {
        stack<int> S;
        stringstream ss(str);
        string s;
        while (ss >> s) {
            if (s.compare("+") == 0) {
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.emplace(a + b);
            } else if (s.compare("-") == 0) {
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.emplace(a - b);
            } else if (s.compare("*") == 0) {
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.emplace(a * b);
            } else {
                S.emplace(stoi(s));
            }
        }
        cout << S.top() << endl;
    }
}

/*
#include <iostream>

using namespace std;

const int MAXN = 1001;

int main()
{
    char c;
    int S[MAXN];
    int n = 0;

    while (cin.get(c))
    {
        if (c == '\n')
        {
            cout << S[0] << endl;
            n = 0;
            continue;
        }
        if (c >= '0' && c <= '9')
        {
            S[n] = c - '0';
            ++n;
            continue;
        }

        --n;
        switch (c)
        {
        case '+':
            S[n - 1] = S[n - 1] + S[n];
            break;
        case '-':
            S[n - 1] = S[n - 1] - S[n];
            break;
        case '*':
            S[n - 1] = S[n - 1] * S[n];
            break;
        default:
            ++n;
            break;
        }
    }

    if (n > 0)
    {
        cout << S[0] << endl;
    }
}
*/