#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        multimap<int, int> plan;
        int N, I;
        cin >> N >> I;
        int level;
        for (int j = 0; j < N; j++) {
            cin >> level;
            plan.insert(pair<int, int>(level, j+1));
        }
        multimap<int, int>::iterator it = plan.begin();
        advance(it, I);
        // for (int j = 1; j < I; j++, it++) {}
        cout << it->second << " " << it->first << endl;
    }
}