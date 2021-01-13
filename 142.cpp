#include <cstdio>
#include <algorithm>

class DSet
{
private:
    int size;
    int *arr;
    // int rootA, rootB;

public:
    DSet(int n) {
        size = n;
        arr = new int[size];
        // for (int i = 0; i < size; i++)
            // arr[i] = -1;
        std::fill(arr, arr + n, -1);
    }

    void join(int a, int b) {
        int rootA = parentIndex(a);
        int rootB = parentIndex(b);

        if (rootA != rootB) {
            if (arr[rootA] < arr[rootB])
                arr[rootB] = rootA;
            else if (arr[rootB] < arr[rootA])
                arr[rootA] = rootB;
            else {
                arr[rootB] = rootA;
                arr[rootA]--;
            }
        }
    }

    int parentIndex(int x) {
        int index = x;
        while (arr[index] >= 0)
            index = arr[index];
        return index;
    }

    int calcMax() {
        int* counter = new int[size];
        // for (int i = 0; i < size; i++)
            // counter[i] = 0;
        std::fill(counter, counter + size, 0);

        for (int i = 0; i < size; i++)
            counter[parentIndex(i)]++;

        int max = counter[0];
        for (int i = 1; i < size; i++)
            if (counter[i] > max)
                max = counter[i];

        return max;
    }
};

int main(void) {
    int T, N, M, a, b;
    scanf("%i", &T);
    // cin >> T;
    while (T--) {
        scanf("%i %i", &N, &M);
        // cin >> N >> M;
        DSet set(N);
        while (M--) {
            scanf("%i %i", &a, &b);
            // cin >> a >> b;
            set.join(a - 1, b - 1);
        }
        printf("%i\n", set.calcMax());
        // cout << set.calcMax() << endl;
    }
    return 0;
}