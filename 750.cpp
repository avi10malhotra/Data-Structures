#include <cstdio>

int main(void) {
    int arr[101];
    int T, head, n, elem, parent, p1, p2;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %d", &head, &n);
        arr[head] = -1;
        while (n-- > 1) {
            scanf("%d %d", &elem, &parent);
            arr[elem] = parent;
        }
        scanf("%d %d", &p1, &p2);
        while(arr[p1] != -1) {
            elem = p1;
            p1 = arr[p1];
            arr[elem] = -1;
        }
        while(arr[p2] != -1)
            p2 = arr[p2];
        printf("%d\n", p2);
    }
}
/*
#include <cstdio>
#include <vector>
#include <string>
struct Node
{
    int val = 0;
    std::vector<Node *> child;
    int size = 0;
    std::vector<int> path;
};

Node* nullNode() {
    return new Node();
}

Node* newNode(int val, Node *parent)
{
    Node *node = new Node;
    node->val = val;
    (node->path).reserve(100);
    (node->child).reserve(100);
    node->path = parent->path;
    (node->path).emplace_back(val);
    return node;
}

bool insertNode(int par, int mem, Node *parNode) {
    for (int i = 0; i < parNode->size; i++) {
        if (parNode->child[i]->val == par) {
            Node *temp = newNode(mem, parNode->child[i]);
            parNode->child[i]->child.emplace_back(temp);
            (parNode->child[i]->size)++;
            return true;
        }
    }
    for (int i = 0; i < parNode->size; i++) {
        bool check = insertNode(par, mem, parNode->child[i]);
        if (check)
            break;
    }
    return false;
}

Node* findNode(int search, Node* head) {
    if (head->val == search)
        return head;
    if (head->size == 0)
        return nullNode();
    for (int i = 0; i < head->size; i++) {
        if (head->child[i]->val == search)
            return head->child[i];
    }
    for (int i = 0; i < head->size; i++) {
        Node *found = findNode(search, head->child[i]);
        if (found->val != 0)
            return found;
    }
    return nullNode();
}

int main(void) 
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int root, size;
        scanf("%d %d", &root, &size);
        Node *head = new Node();
        head->val = root;
        (head->path).emplace_back(root);
        for (int j = 0; j < size - 1; j++)
        {
            int member, parent;
            scanf("%d %d", &member, &parent);
            if (head->val == parent) {
                (head->child).emplace_back(newNode(member, head));
                (head->size)++;
            }
            else
            {
                bool waste = insertNode(parent, member, head);
            }
        }
        int A, B;
        scanf("%d %d", &A, &B);
        Node *nA = findNode(A, head);
        Node *nB = findNode(B, head);
        std::vector<int> pA = nA->path;
        std::vector<int> pB = nB->path;
        int l = pA.size() < pB.size() ? pA.size() : pB.size();
        int lca = -1;
        for (int i = 0; i < l; i++) {
            if (pA[i] == pB[i])
                lca = pA[i];
            else
                break;
            
        }
        printf("%d\n", lca);
    }
}
*/