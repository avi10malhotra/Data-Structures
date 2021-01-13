
#include <iostream>
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    int size;
    LinkedList() { head = nullptr; size = 0; }

    void appendNode(int &);
    void insertNode(int &, int &);
    void deleteNode(int &);
    void reverseFirst(int &, int &);
    void reverseNodes(int &, int &);
    void displayNode(int &);
};

void LinkedList::appendNode(int &num)
{
    Node *newNode = new Node(num);
    Node *nodeptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodeptr = head;
        while (nodeptr->next)
        {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newNode;
    }
    this->size++;
}

void LinkedList::displayNode(int &pos)
{
    Node *nodeptr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        nodeptr = nodeptr->next;
    }
    std::cout << nodeptr->val << std::endl;
}

void LinkedList::insertNode(int &pos, int &val)
{
    Node *nodeptr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        nodeptr = nodeptr->next;
    }
    Node *newNode = new Node(val);
    newNode->next = nodeptr->next;
    nodeptr->next = newNode;
    this->size++;
}

void LinkedList::deleteNode(int &pos)
{
    Node *nodeptr = head;
    if (pos == 1) {
        head = head->next;
        delete nodeptr;
        return;
    }
    Node *prev = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = nodeptr;
        nodeptr = nodeptr->next;
    }
    prev->next = nodeptr->next;
    delete nodeptr;
    this->size--;
}

void LinkedList::reverseFirst(int &start,int &end) {
    reverseNodes(++start, end);
    Node *nodeptr = head;
    for (int i = 0; i < end - 1; i++) {
        nodeptr = nodeptr->next;
    }
    Node *temp = head;
    head = head->next;
    temp->next = nodeptr->next;
    nodeptr->next = temp;

}


void LinkedList::reverseNodes(int &first, int &last)
{
    Node *temp = new Node(-1);
    temp->next = head;
    Node *before = temp;
    for (int i = 0; i < first - 1; i++) {
        before = before->next;
    }
    Node *start = before->next;
    Node *end = start->next;

    for (int i = 0; i < last - first; i++) {
        start->next = end->next;
        end->next = before->next;
        before->next = end;
        end = start->next;
    }

}

int main(void)
{
    LinkedList *list = new LinkedList;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        list->appendNode(val);
    }

    int op;
    std::cin >> op;
    for (int i = 0; i < op; i++)
    {
        int tag;
        std::cin >> tag;

        if (tag == 1 || tag == 3)
        {
            int a, b;
            std::cin >> a >> b;
            if (tag == 1) 
                list->insertNode(a, b);
            else {
                if (a == 1)
                    list->reverseFirst(a, b);
                else
                    list->reverseNodes(a, b);
            }
        }
        else
        {
            int pos;
            std::cin >> pos;
            if (tag == 2)
                list->deleteNode(pos);
            else
                list->displayNode(pos);
        }
    }
}