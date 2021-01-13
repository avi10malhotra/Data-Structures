#include <cstdio>
#include <deque>

typedef long long int lli;

void bucketsort(int *arr, int n, int exp) {
    int *out = new int[n];
    int i, bucket[1024] = {0};

    for (i = 0; i < n; i++) 
        bucket[(arr[i] / exp) % 1024]++; 
  
    for (i = 1; i < 1024; i++) 
        bucket[i] += bucket[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) {
        out[bucket[(arr[i] / exp) % 1024] - 1] = arr[i]; 
        bucket[(arr[i] / exp) % 1024]--; 
    }

    for (int i = 0; i < n; i++)
        arr[i] = out[i];

    delete out;
}

int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixsort(int *arr, int n) {
    int m = getMax(arr, n);

    for (int i = 1; m / i > 0; i *= 1024)
        bucketsort(arr, n, i);
}

int main(void) {
    int T, n, Q;
    int f1, f2, f3;
    scanf("%i", &T);
    while (T--) {
        scanf("%i %i", &n, &Q);
        int *seq = new int[n];
        // seq.emplace_back(1);
        // seq.emplace_back(1);
        seq[0] = seq[1] = 1;
        f1 = f2 = f3 = 1;

        for (int i = 0; i < n-2; i++) {
            f3 = (f1 + f2) % Q;
            seq[i+2] = f3;
            // seq.emplace_back(f3);
            f1 = f2; 
            f2 = f3;
        }

        radixsort(seq, n);
        lli sum = 0;
        for (int i = 0; i < n; i++)
            sum += ((lli)seq[i] * (lli)(i+1)) % Q;
        
        printf("%lli\n", sum%Q);

        delete seq;
    }
}

/*
#include <stdio.h>
#include <string.h>
using namespace std;
int fibo[5000000];
int temp[5000000];

const static int radix = 1024;
static int p[] = { 0,10,20,30 };

int main()
{
	int t;
	scanf("%d", &t);
	while (t > 0)
	{
		fibo[0] = 0;
		fibo[1] = 1;
		t--;
		int n, q;
		int d = 1;
		scanf("%d%d", &n, &q);
		if (q > 1023)	d++;
		if (q > 1024 * 1023 - 1)	d++;
		for (int i = 2; i <= n; i++)
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) >= q ? (fibo[i - 1] + fibo[i - 2]) % q : (fibo[i - 1] + fibo[i - 2]);
		int count[radix];
		for (int i = 0; i < d; i++)
		{
			memset(count, 0, sizeof(int) * radix);
			for (int j = 1; j <= n; j++)
				count[fibo[j] >> p[i] & (radix - 1)]++;
			for (int j = 1; j < radix; j++)
				count[j] += count[j - 1];
			for (int j = n - 1; j >= 0; j--)
				temp[count[fibo[j + 1] >> p[i] & (radix - 1)]--] = fibo[j + 1];
			memcpy(fibo, temp, sizeof(int)*(n + 1));
		}
		long long res = 0;
		for (long long i = 1; i <= n; i++)
			res += ((i*fibo[i]) >= q ? (i*fibo[i]) % q : (i*fibo[i]));
		res = res % q;
		printf("%lld\n", res);
	}
	return 0;
}
*/