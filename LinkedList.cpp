#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertattail(Node *&tail, int val)
{
    Node *newnode = new Node(val);

    tail->next = newnode;
    tail = newnode;
}

void insertathead(Node *&head, int val)
{
    Node *newnode = new Node(val);

    newnode->next = head;
    head = newnode;
}

// 3 cases : starting, ending ,middle
void insertatanyposition(Node *&head, Node *&tail, int pos, int val)
{
    // at starting position
    if (pos == 1)
    {
        insertathead(head, val);
        return;
    }

    Node *newnode = new Node(val);
    Node *temp = head;

    int c = 1;
    while (c < pos - 1)
    {
        temp = temp->next;
        c++;
    }

    // last position
    if (temp->next == NULL)
    {
        insertattail(tail, val);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void display(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "LinkedList is null";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// 2 cases : starting and end
void deletenode(Node *&head, Node *&tail, int pos)
{

    Node *curr = head;
    Node *prev = NULL;

    // delete head
    if (pos == 1)
    {
        head = curr->next;
        curr->next = NULL;
        delete curr;
    }

    else
    {
        // delete at any postion and end
        int c = 1;
        while (c < pos)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        // assigning the tail to maintain the consistency - {116-120}
        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node *node1 = new Node(13);

    Node *head = node1;
    Node *tail = node1;

    // insertathead(head, 13);
    insertattail(tail, 36);
    insertattail(tail, 39);
    insertattail(tail, 40);
    insertattail(tail, 41);

    // insertathead(head, 36);
    // insertathead(head, 39);
    // insertathead(head, 52);
    // insertathead(head, 65);

    display(head);
    // cout << "tail: " << tail->data << endl;

    // insertatanyposition(head, tail, 1, 20);
    // insertatanyposition(head, tail, 5, 37);
    deletenode(head, tail, 5);
    display(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}