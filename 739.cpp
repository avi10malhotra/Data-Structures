#include <iostream>

class Node 
{
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};


class LinkedList 
{
private:
    Node *prev;
    Node *ref;
    int size = 0;

public:
    LinkedList() {
        prev = nullptr;
        ref = nullptr;
    }
    void appendNode(int, bool);
    void insertNode(int, int);
    void deleteNode(int);
    void displayNode(int);
};

void LinkedList::appendNode(int num, bool last)
{
    Node *newNode = new Node(num);
    Node *nodeptr;
    size++;

    if (!ref)
    {
        ref = newNode;
    }
    else
    {
        nodeptr = ref;
        while (nodeptr->next)
        {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newNode;
        if (last) {
            newNode->next = ref;
            prev = newNode;
        }
    }
}

void LinkedList::displayNode(int pos)
{
    Node *nodeptr = ref;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = nodeptr;
        nodeptr = nodeptr->next;
    }
    std::cout << nodeptr->val << std::endl;
    ref = nodeptr;
}

void LinkedList::insertNode(int pos, int val)
{
    Node *nodeptr = ref;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = nodeptr;
        nodeptr = nodeptr->next;
    }
    size++;
    Node *newNode = new Node(val);
    newNode->next = nodeptr->next;
    prev = nodeptr;
    nodeptr->next = newNode;
    ref = newNode;
}

void LinkedList::deleteNode(int pos)
{
    Node *nodeptr = ref;
    for (int i = 0; i < pos - 1; i++) {
        prev = nodeptr;
        nodeptr = nodeptr->next;
    }
    prev->next = nodeptr->next;
    delete nodeptr;
    ref = prev->next;
}

int main(void) {
    LinkedList *list = new LinkedList;
    
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int val;
        std::cin >> val;
        list->appendNode(val, false);
    }
    int last;
    std::cin >> last;
    list->appendNode(last, true);

    int op;
    std::cin >> op;
    for (int i = 0; i < op; i++) {
        int tag;
        std::cin >> tag;

        if (tag == 1) {
            int pos, val;
            std::cin >> pos >> val;
            list->insertNode(pos, val);
        }
        else {
            int pos;
            std::cin >> pos;
            if (tag == 2)
                list->deleteNode(pos);
            else
                list->displayNode(pos);
        }
    }
}