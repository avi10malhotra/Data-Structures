#include <cstdio>
#include <cmath>
#include <stack>
typedef long long int lli;
int arr[1000000];

lli calcMaxArea(int &n) {
    lli max = 0, h, l;
    std::stack<int> index;
    for (int i = 0; i <= n; i++) {
        while (i == n || (!index.empty() && arr[i] < arr[index.top()]) ) {
            if (i == n && index.empty()) {
                h = 0;
                i++;
            } else {
                h = arr[index.top()];
                index.pop();
            }
            l = index.empty() ? -1 : index.top();
            max = std::max(max, h * (i - l - 1));
        }
        index.emplace(i);
    }
    return max;
}

int main(void) {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        printf("%lli\n", calcMaxArea(N));
    }
}