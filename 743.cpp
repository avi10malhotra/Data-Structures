#include <iostream>
#include <string>
#include <map>
#include <algorithm>

char open[3] = {'{', '(', '['};
char close[3] = {'}', ')', ']'};
int syntaxChecker(char c)
{
    for (int i = 0; i < 3; i++)
    {
        if (c == open[i])
            return i + 1;
        else if (c == close[i])
            return -(i + 1);
    }
    return 0;
}

int checkered(std::string str)
{
    std::map<int, char> sentence;
    for (int i = 0; i < str.length(); i++)
    {
        int bracket = syntaxChecker((char)str[i]);
        if (bracket > 0)
        {
            sentence[i] = str[i];
        }
        else if (bracket < 0)
        {
            int check = -bracket;
            int index = i;
            char match = open[check - 1];
            std::map<int, char>::iterator it = sentence.end();
            bool deleted = false;
            if (!sentence.empty())
                it--;
            if (it->second == match) {
                sentence.erase(it);
                deleted = true;
            }

            if (!deleted)
                return index + 1;
        }
    }
    if (!sentence.empty())
        return sentence.begin()->first + 1;
    else
        return -1;
}

int main(void)
{
    std::string str;
    while (std::getline(std::cin, str))
    {
        int ans = checkered(str);
        if (ans != -1)
            std::cout << ans << std::endl;
        else
            std::cout << "Success\n";
    }
}

// #include <stdio.h>
// #include <vector>
// using namespace std;
// char str[100001];
// vector<int> p;
// vector<char> c;

// int min(int a, int b)
// {
//     return a < b ? a : b;
// }

// int main()
// {
//     while (fgets(str, 100005, stdin))
//     {
//         int pos = 0;
//         for (int i = 0; str[i] != '\0'; i++)
//         {
//             if (str[i] == '(' || str[i] == '[' || str[i] == '{')
//             {
//                 c.push_back(str[i]);
//                 p.push_back(i + 1);
//             }
//             else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
//             {
//                 char back = c.back();
//                 if (c.empty() || (str[i] == ')' && back != '(') || (str[i] == ']' && back != '[') || (str[i] == '}' && back != '{'))
//                 {
//                     pos = i + 1;
//                     break;
//                 }
//                 c.pop_back();
//                 p.pop_back();
//             }
//         }
//         if (c.empty() && pos == 0)
//             printf("Success\n");
//         else
//         {
//             if (pos)
//                 printf("%d\n", pos);
//             else
//                 printf("%d\n", p.front());
//         }
//         c.clear();
//         p.clear();
//     }
//     return 0;
// }