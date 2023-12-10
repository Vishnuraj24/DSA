#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node();
};

void insertathead(Node *&head, int val)
{
    Node *newnode = new Node(val);
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertattail(Node *&tail, int val)
{
    Node *newnode = new Node(val);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertatanyposition(Node *&head, Node *&tail, int pos, int val)
{
    // new node
    Node *newnode = new Node(val);
    // insert at pos = 1 i.e, head
    if (pos == 1)
    {
        insertathead(head, val);
        return;
    }
    // cuurent node
    Node *cur = head;
    int c = 1;
    // inserting any where in the middle
    while (c < pos - 1)
    {
        cur = cur->next;
        c++;
    }
    // last position
    if (cur->next == NULL)
    {
        insertattail(tail, val);
        return;
    }
    newnode->next = cur->next;
    cur->next->prev = newnode;
    cur->next = newnode;
    newnode->prev = cur;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertathead(head, 2);
    insertathead(head, 3);
    insertattail(tail, 0);
    insertattail(tail, 9);
    // insertattail(tail, 10);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    // 3 2 1 8 0 9
    insertatanyposition(head, tail, 4, 8);
    insertatanyposition(head, tail, 2, 5);
    insertatanyposition(head, tail, 1, 10);

    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
}