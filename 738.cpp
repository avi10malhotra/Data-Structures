#include <iostream>

void fib(int f[], int n) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10;
}

int main(void) {
    int num;
    int f[60] = {0};
    fib(f, 60);
    while (std::cin >> num)
        std::cout << f[num % 60] << std::endl;
    return 0;
}

// #include <iostream>
// #include <math.h>
// #include <stdio.h>
// using namespace std;
// int fibo(int n)
// {
//     int fib1 = 0;
//     int fib2 = 1;
//     if (n <= 1)
//         return n;
//     else
//     {
//         for (int i = 1; i < n; i++)
//         {
//             if (i % 2 == 0)
//                 fib2 = (fib1 + fib2) % 10;
//             else
//                 fib1 = (fib1 + fib2) % 10;
//         }
//         if (n % 2 == 0)
//             return fib1;
//         else
//             return fib2;
//     }
// }

// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         cout << fibo(n) << endl;
//     }
//     return 0;
// }