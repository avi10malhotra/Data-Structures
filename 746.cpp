#include <iostream>
#include <queue>

// Syntax to create a min heap for priority queue
// priority_queue<int, vector<int>, greater<int>> g = gq;

int main(void) {
    int N;
    while(std::cin >> N) {
        std::queue<int> q;
        for (int i = 0; i < N; i++) {
            int A, W, L;
            std::cin >> A >> W >> L;
            // if front <= A, keep removing until front > A
            while (q.front() <= A && q.size() != 0)
                q.pop();
            // if empty, take input
            if (q.empty() && i == N - 1) {
                q.emplace(A);
                continue;
            }
            if (q.empty()) {
                q.emplace(A + W);
                continue;
            }
            // if last person drops
            if (q.size() > L && i == N - 1) {
                q.back() = -1;
                continue;
            }
            // if size > L continue
            if (q.size() > L || i == N - 1)
                continue;
            // if front > A, add back+W
            if (q.front() > A)
                q.emplace(q.back() + W);
        }
        std::cout << q.back() << std::endl;
    }
}

// #include <iostream>
// #include <queue>
// #include <cstdio>
// #include <cmath>
// using namespace std;
// struct node
// {
//     int a, o, l;
//     int begt, fint;
// };
// queue<node> Q;
// int main()
// {
//     //freopen("1.txt","r",stdin) ;
//     int n;
//     node A;
//     while (~scanf("%d", &n))
//     {
//         while (!Q.empty())
//             Q.pop();
//         for (int i = 1; i <= n - 1; i++)
//         {
//             scanf("%d%d%d", &A.a, &A.o, &A.l);
//             while (!Q.empty() && Q.front().fint <= A.a)
//                 Q.pop();
//             if (A.l >= Q.size())
//             {
//                 if (Q.size())
//                     A.begt = max(A.a, Q.back().fint);
//                 else
//                     A.begt = A.a;
//                 A.fint = A.begt + A.o;
//                 Q.push(A);
//                 //cout << A.begt << ' ' << A.fint << endl ;
//             }
//         }
//         scanf("%d%d%d", &A.a, &A.o, &A.l);
//         while (!Q.empty() && Q.front().fint <= A.a)
//             Q.pop();
//         if (A.l < Q.size())
//             printf("-1\n");
//         else
//         {
//             if (Q.size())
//                 printf("%d\n", max(A.a, Q.back().fint));
//             else
//                 printf("%d\n", A.a);
//         }
//     }
//     return 0;
// }