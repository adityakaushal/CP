#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = nullptr;
    return tmp;
}

class LinkedList
{
public:
    Node *head;
    Node *rear;
    int size;

    LinkedList()
    {
        head = nullptr;
        rear = nullptr;
        size = 0;
    }

    Node *reverseKSizeGroup(int k)
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;
        while (current != nullptr && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != NULL)
        head->next = reverseKSizeGroup(k);
        return prev;
    }

    void add(int data)
    {
        Node *tmp = newNode(data);
        if (head == nullptr)
        {
            head = tmp;
            rear = tmp;
        }
        else
        {
            rear->next = tmp;
            rear = rear->next;
        }
    }

    void traverse()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->next == NULL)
            {
                cout << tmp->data << " ";
            }
            else
            {
                cout << tmp->data << "->";
            }
            tmp = tmp->next;
        }
    }

    void Reverse()
    {
        Node *prev = NULL;
        Node *next;
        Node *current = head;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList ll;
    int N, data;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        ll.add(data);
    }
    int k;
    cin >> k;
    ll.reverseKSizeGroup(k);
    cout << endl;
 
}
