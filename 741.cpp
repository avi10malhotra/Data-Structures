#include <cstdio>
#include <iostream>

int heads(int arr[100][10], int n, int m, int col)
{
    if (m == col)
    {
        int totHeads = 0;
        int rHeads = 0;
        for (int i = 0; i < n; i++)
        {
            rHeads = 0;
            for (int j = 0; j < m; j++)
                rHeads += arr[i][j];
            if (rHeads <= m / 2)
                rHeads = m - rHeads;
            totHeads += rHeads;
        }
        return totHeads;
    }
    else
    {
        int flippedC, unflippedC;
        unflippedC = heads(arr, n, m, col + 1);
        for (int i = 0; i < n; i++)
            arr[i][col] = 1 ^ arr[i][col];
        flippedC = heads(arr, n, m, col + 1);
        return std::max(flippedC, unflippedC);
    }
}

int main(void)
{
    int n, m;
    int arr[100][10];
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < n; i++)
        {
            char temp[m];
            scanf("%s", temp);
            for (int j = 0; j < m; j++)
                arr[i][j] = (int)(temp[j] - '0');
        }
        printf("%d\n", heads(arr, n, m, 0));
    }
}
#include <iostream>
#include <string>
#include <cstdio>

int countRows(int* row, int m) {
    int heads = 0, tails = 0;
    for (int i = 0; i < m; i++)
        row[i] == 1 ? heads++ : tails++;
    return std::max(heads, tails);
}

int calcHeads(int** arr, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++)
        count += countRows(arr[i], m);
    return count;
}

void flipC(int** arr, int n, int col) {
    for (int i = 0; i < n; i++)
        arr[i][col] = 1 - arr[i][col];
}

int maxHeads(int** arr, int n, int m, int mStart) {
    int** arrCopy = new int*[n];
    for (int i = 0; i < n; i++)
        arrCopy[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arrCopy[i][j] = arr[i][j];

    if (mStart >= m) {
        int heads = calcHeads(arrCopy, n, m);
        for (int i = 0; i < n; i++)
            delete (arrCopy[i]);
        delete (arrCopy);
        return heads;
    }

    int original = maxHeads(arrCopy, n, m, mStart + 1);
    flipC(arrCopy, n, mStart);
    int flipped = maxHeads(arrCopy, n, m, mStart + 1);

    for (int i = 0; i < n; i++)
        delete (arrCopy[i]);
    delete (arrCopy);

    return std::max(original, flipped);
}

int main(void) {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        int** arr = new int*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[m];
            char temp[m];
            scanf("%s", temp);
            for (int j = 0; j < m; j++)
                arr[i][j] = (int)(temp[j] - '0');
        }
        printf("%d\n", maxHeads(arr, n, m, 0));
    }
}

// 5 4 0111 1100 0100 1000 1011 
// 5 4 0101 0110 1001 1000 0011 
// 2 2 10 01
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int baseten(int n)
{
    int num = n;
    int baseten = 0;

    // Initializing base value to 1
    int base = 1;

    int temp = num;
    while (temp)
    {
        int rem = temp % 10;
        temp = temp / 10;

        baseten = baseten + rem * base;

        base = base * 2;
    }

    return baseten;
}
int counttally(int v, int c)
{

    int h;
    int tally;

    for (h = 0; v; v >>= 1)
    {
        h = h + (v & 1);
    }
    tally = (c - h) - h;

    return tally;
}
int counthead(int v, int c)
{

    int h;

    for (h = 0; v; v >>= 1)
    {
        h = h + (v & 1);
    }

    return h;
}

int decide(std::vector<int> &arr, int r, int c)
{
    //create a vector for row flips
    vector<int> flippedrowvector(r);

    int combolimit = int(pow(2, c));
    int flipper = combolimit - 1;

    vector<int> headcountcombo(combolimit);
    for (int i = 0; i < combolimit; i++)
    {
        headcountcombo[i] = 0; // initialize head count for combination to zero
        // Get impact on rows for each column combination and get tally of tail-head
        for (int j = 0; j < r; j++)
        {
            flippedrowvector[j] = i ^ arr[j];

            if (counttally(flippedrowvector[j], c) > 0)
            {

                flippedrowvector[j] = flipper ^ flippedrowvector[j]; //flip row if t-h>0
            }
            // count heads for each row
            headcountcombo[i] = headcountcombo[i] + counthead(flippedrowvector[j], c);
        }
    }

    int max = headcountcombo[0];
    for (int i = 0; i < combolimit; i++)
    {
        if (headcountcombo[i] > max)
            max = headcountcombo[i];
    }
    return max;
}
int main()
{
    int r1 = 0;
    int c1 = 0;
    while (cin >> r1)
    {

        cin >> c1;
        vector<int> rowvector(r1);
        int bnum;
        for (int i = 0; i < r1; i++)
        {

            cin >> bnum; // taking the binary and converting to base 10
            rowvector[i] = baseten(bnum);
        }
        // all sequencing and processing is done by decide function
        cout << decide(rowvector, r1, c1) << endl;
    }
}
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>

// using namespace std;

// bool mtx[101][20];
// int rCount[101];
// int cCount[101];
// int ans;
// int col;
// int row;

// void flip(int tar)
// {
//     for (int i = 0; i < col; i++)
//     {
//         if (mtx[tar][i])
//         {
//             mtx[tar][i] = 0;
//             cCount[i]--;
//         }
//         else
//         {
//             mtx[tar][i] = 1;
//             cCount[i]++;
//         }
//     }
// }

// void alg(int cRow)
// {
//     if (cRow == row - 1)
//     {
//         //handle column best case
//         int k = row / 2;
//         int temp = 0;
//         int n;
//         for (int i = 0; i < col; i++)
//         {
//             if (cCount[i] < k)
//             {
//                 n = row - cCount[i];
//                 temp += n;
//             }
//             else
//             {
//                 temp += cCount[i];
//             }
//         }
//         if (temp > ans)
//         {
//             ans = temp;
//         }
//     }
//     else
//     {
//         int next = cRow + 1;
//         alg(next); //no flip case
//         flip(next);
//         alg(next); //flip case
//     }
// }

// void flipC(int tar)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if (mtx[i][tar])
//         {
//             mtx[i][tar] = 0;
//             rCount[i]--;
//         }
//         else
//         {
//             mtx[i][tar] = 1;
//             rCount[i]++;
//         }
//     }
// }

// void algC(int cCol)
// {
//     if (cCol == col - 1)
//     {
//         //handle column best case
//         int k = col / 2;
//         int temp = 0;
//         int n;
//         for (int i = 0; i < row; i++)
//         {
//             if (rCount[i] < k)
//             {
//                 n = col - rCount[i];
//                 // cCount[i] = n;
//                 temp += n;
//             }
//             else
//             {
//                 temp += rCount[i];
//             }
//         }
//         if (temp > ans)
//         {
//             ans = temp;
//         }
//     }
//     else
//     {
//         int next = cCol + 1;
//         algC(next); //no flip case
//         flipC(next);
//         algC(next); //flip case
//     }
// }

// int main()
// {
//     while (scanf("%d", &row) != EOF)
//     {
//         scanf("%d", &col);
//         int in;
//         ans = 0;

//         for (int i = 0; i < col; i++)
//         {
//             cCount[i] = 0;
//         }
//         for (int i = 0; i < row; i++)
//         {
//             rCount[i] = 0;
//             for (int j = 0; j < col; j++)
//             {
//                 scanf("%1d", &in);
//                 mtx[i][j] = in;
//                 if (mtx[i][j])
//                 {
//                     rCount[i]++;
//                     cCount[j]++;
//                 }
//             }
//         }
//         /*
// 		for (int i = 0; i < col; i++) {		//generate column count
// 			cCount[i] = 0;
// 			for (int j = 0; j < row; j++) {
// 				if (mtx[j][i]) {
// 					cCount[i]++;
// 				}
// 			}
// 		}
// 		*/
//         if (col > row)
//         {
//             alg(0); //handle row by flipping
//         }
//         else
//         {
//             algC(0); //handle col by flipping
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }


// 5 4 0111 1100 0100 1000 1011 DONE
// 5 4 0101 0110 1001 1000 0011 DONE
// 2 2 10 01 DONE