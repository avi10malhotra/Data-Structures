#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

struct arrOfDict {
    int idx, val;
};

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);
        std::vector<arrOfDict> V(N);
        if (K > N)
            K = N;
        for (int j = 0; j < N; j++) {
            int d;
            scanf("%d", &d);
            V[j] = {j+1, d};
        }
        std::string s;
        while(!V.empty()) {
            K = std::min(K, (int)V.size());
            auto max = V[0];
            int index = 0;
            for (int j = 1; j < K; j++) {
                if (V[j].val > max.val) {
                    index = j;
                    max = V[j];
                }
            }
            // std::cout << max.idx << " ";
            printf("%d", max.idx);
            if (V.size() != 1)
                printf(" ");
            V.erase(V.begin() + index);
            for (int j = 0; j < K - 1; j++)
                V[j].val--;
            std::vector<arrOfDict> temp = {V.begin(), V.begin() + K - 1};
            V.erase(V.begin(), V.begin() + K - 1);
            V.insert(V.end(), temp.begin(), temp.end());
        }
        // if (i != T-1)
        printf("\n");
    }
}
