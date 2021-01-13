#include <iostream>
#include <cmath>

int quadtree(int arr[1024][1024], int size, int xStart, int yStart, int nodes)
{
    if (size == 2 && arr[xStart][yStart] == arr[xStart + 1][yStart] && arr[xStart][yStart] == arr[xStart][yStart + 1] && arr[xStart][yStart] == arr[xStart + 1][yStart + 1])
    {
        return 0;
    }
    else if (size == 2)
    {
        return 4;
    }

    bool check1 = true;
    int ref1 = arr[xStart][yStart];
    for (int i = xStart; i < xStart + size / 2; i++)
    {
        for (int j = yStart; j < yStart + size / 2; j++)
        {
            if (arr[i][j] != ref1)
            {
                check1 = false;
                break;
            }
        }
        if (!check1)
            break;
    }

    //

    bool check2 = true;
    int ref2 = arr[xStart][yStart + size / 2];
    for (int i = xStart; i < xStart + size / 2; i++)
    {
        for (int j = yStart + size / 2; j < yStart + size; j++)
        {
            if (arr[i][j] != ref2)
            {
                check2 = false;
                break;
            }
        }
        if (!check2)
            break;
    }

    //

    bool check3 = true;
    int ref3 = arr[xStart + size / 2][yStart];
    for (int i = xStart + size / 2; i < xStart + size; i++)
    {
        for (int j = yStart; j < yStart + size / 2; j++)
        {
            if (arr[i][j] != ref3)
            {
                check3 = false;
                break;
            }
        }
        if (!check3)
            break;
    }

    //

    bool check4 = true;
    int ref4 = arr[xStart + size / 2][yStart + size / 2];
    for (int i = xStart + size / 2; i < xStart + size; i++)
    {
        for (int j = yStart + size / 2; j < yStart + size; j++)
        {
            if (arr[i][j] != ref4)
            {
                check4 = false;
                break;
            }
        }
        if (!check4)
            break;
    }
    nodes = 0;
    if (!check1)
        nodes = 1 + quadtree(arr, size / 2, xStart, yStart, nodes);
    else
        nodes++;
    if (!check2)
        nodes += 1 + quadtree(arr, size / 2, xStart, yStart + size / 2, nodes);
    else
        nodes++;
    if (!check3)
        nodes += 1 + quadtree(arr, size / 2, xStart + size / 2, yStart, nodes);
    else
        nodes++;
    if (!check4)
        nodes += 1 + quadtree(arr, size / 2, xStart + size / 2, yStart + size / 2, nodes);
    else
        nodes++;

    //

    if (check1 && check2 && check3 && check4 
        && ref1 == ref2 
        && ref1 == ref3 
        && ref1 == ref4)
            nodes = 0;

    return nodes;
}

int main(void)
{
    int k;
    while (std::cin >> k)
    {
        int n = pow(2, k);
        int arr[1024][1024];
        for (int i = 0; i < n; i++)
        {
            std::string temp;
            std::cin >> temp;
            for (int j = 0; j < temp.length(); j++)
            {
                arr[i][j] = (int)(temp[j] - '0');
            }
        }
        if (n == 1) {
            std::cout << 1 << std::endl;
            continue;
        }
        std::cout << 1 + quadtree(arr, n, 0, 0, 1) << std::endl;
    }
}

// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;

// int findNumSubTree(int pic[1024][1024], int rowStart, int rowEnd, int colStart, int colEnd)
// {

//     if (rowStart >= rowEnd - 1 || colStart >= colEnd - 1)
//     {
//         return 1;
//     }

//     int colour = pic[rowStart][colStart];

//     for (int r = rowStart; r < rowEnd; r++)
//     {
//         for (int c = colStart; c < colEnd; c++)
//         {
//             if (pic[r][c] != colour)
//             {
//                 int count = 1;

//                 count += findNumSubTree(pic, rowStart, (rowEnd + rowStart) / 2, colStart, (colEnd + colStart) / 2);
//                 count += findNumSubTree(pic, (rowEnd + rowStart) / 2, rowEnd, colStart, (colEnd + colStart) / 2);
//                 count += findNumSubTree(pic, rowStart, (rowEnd + rowStart) / 2, (colEnd + colStart) / 2, colEnd);
//                 count += findNumSubTree(pic, (rowEnd + rowStart) / 2, rowEnd, (colEnd + colStart) / 2, colEnd);

//                 return count;
//             }
//         }
//     }

//     return 1;
// }

// int main()
// {

//     int n, k;

//     while (cin >> k)
//     {

//         // cin >> k;
//         n = pow(2, k);

//         int picture[1024][1024];
//         // int** picture = new int*[n];
//         for (int r = 0; r < n; r++)
//         {

//             // picture[r] = new int[n];

//             string line;
//             cin >> line;

//             for (int c = 0; c < n; c++)
//             {
//                 picture[r][c] = line.at(c) - '0';
//             }
//         }

//         int count = findNumSubTree(picture, 0, n, 0, n);

//         cout << count;

//         // for(int r = 0; r < n; r++){
//         //     delete picture[r];
//         // }
//         // delete picture;
//     }

//     return 0;
// }