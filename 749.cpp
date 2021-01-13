#include <cstdio>

int globalCount;

int search(int in[], int val, int N)
{
    for (int i = 0; i < N; i++)
        if (in[i] == val)
            return i;
    return -1;
}

void postorder(int pre[], int in[], int N, int size)
{
    int root = search(in, pre[0], N);

    if (root != 0)
        postorder(pre + 1, in, root, size);

    if (root != N - 1)
        postorder(pre + root + 1, in + root + 1, N - 1 - root, size);

    globalCount++;
    if (globalCount != size)
        printf("%d ", pre[0]);
    else
        printf("%d\n", pre[0]);
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        int preorder[N], inorder[N];
        for (int j = 0; j < N; j++)
            scanf("%d", &preorder[j]);
        for (int j = 0; j < N; j++)
            scanf("%d", &inorder[j]);

        globalCount = 0;
        postorder(preorder, inorder, N, N);
    }
}