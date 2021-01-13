#include <cstdio>
#include <algorithm>

bool possible(int &m, int arr[], int &n, int &c) {
    int pos = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] - pos >= m) {
            pos = arr[i];
            count++;
            if (count == c)
                return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int &n, int &c) {
    int l = 1, r = arr[n - 1];
    int ans = -1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (possible(m, arr, n, c)) {
            ans = std::max(ans, m);
            l = m + 1;
        } else
            r = m;
    }
    return ans;
}

int main(void) {
    int T;
    scanf("%d", &T);
    // while(T--)
    for (int t = 0; t < T; t++) {
        int N, C;
        scanf("%d %d", &N, &C);
        int arr[N];
        for (int n = 0; n < N; n++)
            scanf("%d", &arr[n]);
        std::sort(arr, arr + N);
        printf("%d\n", largestMinDist(arr, N, C));
    }
}