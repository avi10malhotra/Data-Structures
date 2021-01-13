#include <iostream>
#include <vector>
#include <algorithm>

class Stack 
{
private:
    std::vector<int> data;
    int n = 0;

public:
    int getSize() {
        return n;
    }
    void pop() {
        data.pop_back();
        n--;
    }
    void emplace(int x) {
        data.emplace_back(x);
        n++;
    }
    int findPos(int x) {
        std::vector<int>::iterator it = std::find(data.begin(), data.end(), x);
        if (it != data.end())
            return it - data.begin();
        else
            return -1;
    }
    int getFirst() {
        return data.front();
    }
    int getLast() {
        return data.back();
    }
    bool isEmpty() {
        return data.empty();
    }
    int getVal(int x) {
        std::vector<int>::iterator it = data.begin();
        for (int i = 0; i < x; i++)
            it++;
        return *it;
    }
};

bool checkAye(Stack A, Stack B, int size) {
    Stack S;
    int i = 0;
    while(!A.isEmpty() || i != size) {
        int val = B.getVal(i);
        int posA = A.findPos(val);
        bool checkA = true;

        if (posA == -1 || A.isEmpty()) {
            checkA = false;
        }
        
        if (!checkA) {
            if (S.getLast() != val)
                return false;
            else {
                S.pop();
                i++;
            }
        }
        else {
            int sizeA = A.getSize();
            for (int i = 0; i < sizeA - posA; i++) {
                int temp = A.getLast();
                A.pop();
                S.emplace(temp);
            }
        }
    }
    return true;
}

int main(void) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        Stack stackA;
        for (int j = 0; j < n; j++) {
            int elem;
            std::cin >> elem;
            stackA.emplace(elem);
        }
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            Stack stackB;
            for (int k = 0; k < n; k++) {
                int elem;
                std::cin >> elem;
                stackB.emplace(elem);
            }
            if (checkAye(stackA, stackB, n))
                std::cout << "Aye\n";
            else
                std::cout << "Impossible\n";
        }
    }
}