#include <iostream>
using namespace std;
int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int highs = 0, lows = 0;

        int N;
        cin >> N;
        
        int w1, w2;
        cin >> w1;
        
        for (int j = 1; j < N; j++) {
            cin >> w2;
            if (w1 < w2)
                highs++;
            else if (w1 > w2)
                lows++;
            w1 = w2;
        }
        cout << "Case " << i + 1 << ": " << highs << " " << lows << endl;
    }
}