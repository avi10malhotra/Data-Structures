#include <cstdio>
#include <math.h>

int nodes = 0;
class Quadtree
{
public:
    bool white;
    bool needsBranch;
    Quadtree **children;
    Quadtree *parent;

    Quadtree() { needsBranch = false; }

    void addBranch(Quadtree *b1, Quadtree *b2, Quadtree *b3, Quadtree *b4);
    Quadtree* makeQuadtree(Quadtree *root, bool **arr, int r, int c, int len);
    void changeQuadtree(Quadtree *root, int row, int col, int size);
};

void Quadtree::addBranch(Quadtree *b1, Quadtree *b2, Quadtree *b3, Quadtree *b4) {
    children = new Quadtree *[4];
    children[0] = b1;
    children[1] = b2;
    children[2] = b3;
    children[3] = b4;
}

Quadtree* Quadtree::makeQuadtree(Quadtree *root, bool **arr, int row, int col, int len) {
    Quadtree *t = new Quadtree();
    t->parent = root;

    bool needsChildren = false;
    
    for (int r = row; r < row + len; r++)
        for (int c = col; c < col + len; c++)
            if (arr[row][col] != arr[r][c]) {
                needsChildren = true;
                goto quit;
            }
quit:
    if (!needsChildren)
        t->white = arr[row][col];
    else {
        int size = len / 2;
        t->needsBranch = true;
        t->addBranch(
            makeQuadtree(t, arr, row, col, size),
            makeQuadtree(t, arr, row, col + size, size),
            makeQuadtree(t, arr, row + size, col, size),
            makeQuadtree(t, arr, row + size, col + size, size) );
    }
    nodes++;
    return t;
}

void Quadtree::changeQuadtree(Quadtree *root, int row, int col, int size) {
    if (size > 1) {
        if (!root->needsBranch) {
            root->addBranch(new Quadtree(), new Quadtree(), new Quadtree(), new Quadtree());
            nodes += 4;
            root->children[0]->white = root->children[1]->white = root->children[2]->white = root->children[3]->white = root->white;
            root->needsBranch = true;
            root->children[0]->parent = root->children[1]->parent = root->children[2]->parent = root->children[3]->parent = root;
        }
        int half = size / 2;
        if (row < half) {
            if (col < half)
                changeQuadtree(root->children[0], row, col, half);
            else
                changeQuadtree(root->children[1], row, col - half, half);
        } else {
            if (col < half)
                changeQuadtree(root->children[2], row - half, col, half);
            else
                changeQuadtree(root->children[3], row - half, col - half, half);
        }
    } else {
        root->white = !root->white;
        while (root->parent != nullptr) {
            Quadtree *temp = root->parent;
            if (!temp->children[0]->needsBranch && !temp->children[1]->needsBranch && !temp->children[2]->needsBranch && !temp->children[3]->needsBranch
                && temp->children[0]->white == temp->children[1]->white
                && temp->children[0]->white == temp->children[2]->white
                && temp->children[0]->white == temp->children[3]->white ) 
            {
                root->parent->needsBranch = false;
                root->parent->white = root->white;
                root = root->parent;
                nodes -= 4;
            } else
                break;
        }
    }
}

int main(void) {
    int T, N;
    bool **arr = new bool *[1024];
    for (int i = 0; i < 10124; i++)
        arr[i] = new bool[1024];
    scanf("%d", &T);
    while (T--) {
        nodes = 0;
        scanf("%d", &N);
        N = pow(2, N);

        getchar();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                arr[i][j] = (getchar() == '0');
            getchar();
        }

        Quadtree *tree = new Quadtree();
        tree = tree->makeQuadtree(nullptr, arr, 0, 0, N);
        int k, r, c;
        scanf("%d", &k);
        while(k--) {
            scanf("%d %d", &r, &c);
            r--, c--;
            tree->changeQuadtree(tree, r, c, N);
            printf("%d\n", nodes);
        }
    }
}