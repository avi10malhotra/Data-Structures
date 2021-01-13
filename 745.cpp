#include <iostream>
#include <vector>

class Stack 
{
private:
    std::vector <int> data;
    int max = 0;

public:
    void pop()
    {
        bool recalc = false;
        if (data.back() == max)
            recalc = true;
        data.pop_back();
        if (recalc)
            calcMax();
    }
    void emplace(int &x) 
    {   
        if (x > max) 
            max = x;
        data.emplace_back(x);
    }
    void calcMax() {
        max = -1;
        for (auto &it : data) 
            if (it > max)
                max = it;
    } 

    int getMax() { return max; }

};

int main(void) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        Stack S;
        for (int j = 0; j < n; j++)
        {
            int elem;
            std::cin >> elem;
            S.emplace(elem);
        }
        int num;
        std::cin >> num;
        for (int k = 0; k < num; k++) 
        {
            char op;
            std::cin >> op;
            if (op == 'm')
                std::cout << S.getMax() << std::endl;
            else if (op == 'r')
                S.pop();
            else {
                int val;
                std::cin >> val;
                S.emplace(val);
            }
        }
    }
}