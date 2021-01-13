#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
using namespace std;
struct test {
    int start, mid, end;
};

test newTest(int s, int m, int e) {
    test *t = new test;
    t->start = s, t->mid = m, t->end = e;
    return *t;
}

bool order(test t1, test t2) {
    return t1.mid < t2.mid;
}

int main(void)
{
    deque<test> yay;
    yay.emplace_back(newTest(1, 2, 3));
    yay.emplace_back(newTest(0, 0, 1));
    yay.emplace_back(newTest(6, 9, 9));
    std::sort(yay.begin(), yay.end(), order);
}

// int main(void) {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++) {
//         deque<int> cards;
//         int numI;
//         cin >> numI;
//         string str;
//         getline(cin, str);
//         stringstream ss(str);
//         for (int j = 0; j < numI; j++) {
//             getline(cin, str);
//             stringstream ss(str);
//             char c;
//             ss >> c;
//             if (c == 'Q') {
//                 int which;
//                 ss >> which;
//                 // cout << cards[which - 1] << endl;
//                 cout << *(cards.begin() + which - 1) << endl;
//             }
//             else if (c == 'I') {
//                 char where;
//                 int val;
//                 ss >> where;
//                 ss >> val;
//                 where == 'H' ? cards.emplace_front(val) : cards.emplace_back(val);
//             }
//             else {
//                 char pop;
//                 ss >> pop;
//                 pop == 'H' ? cards.pop_front() : cards.pop_back();
//             }
//         }
//     }
// }

/*
2
6
I H 5
I B 4
I H 3
R B
I B 6
Q 2
8
I H 1
I H 2
I H 3
R B
Q 1
I B 4
R H
Q 1
*/