#include <iostream>
using namespace std;

int arr[100000];
int sum = 0;
int count = 0;

void heapifyUp(int i)
{
    int parent = i / 2;
    if (!parent)
        return;
    if (i && arr[parent] < arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        heapifyUp(parent);
    }
}

void heapifyDown(int i)
{
    int left = 2 * i, right = 2 * i + 1;
    int largest = i;

    if (left <= count && arr[left] > arr[largest])
        largest = left;
    if (right <= count && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyDown(largest);
    }
}

void buildHeap()
{
    for (int i = (count / 2) - 1; i > 0; i--)
        heapifyDown(i);
}

void removeMax()
{
    sum -= arr[1];
    arr[1] = arr[count];
    count--;
    heapifyDown(1);
}
int main(void)
{
    int N, num;
    char op;
    while (cin >> N)
    {
        do
        {
            cin >> op;
            N--;
            if (op != 'r')
            {
                cin >> arr[1];
                sum = arr[1], count = 1;
                break;
            }
            cout << 0 << endl;
        } while (op == 'r' && N);
        while (N)
        {
            cin >> op;
            if (op == 'a')
            {
                cin >> num;
                sum += num;
                arr[count + 1] = num;
                heapifyUp(count + 1);
                count++;
            }
            else if (op == 'p')
            {
                removeMax();
            }
            else
                cout << sum << endl;
            N--;
        }
    }
}