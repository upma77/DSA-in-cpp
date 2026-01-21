#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int data)
    {
        value = data;
        next = NULL;
    }
};

class linkedlist
{
public:
    Node *head;

    linkedlist()
    {
        head = NULL;
    }

    void InsertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
Node *mergeLinkedLists(Node *&head1, Node *&head2)
{
    Node *dummyheadnode = new Node(-1);
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *ptr3 = dummyheadnode;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->value < ptr2->value)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if (ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }

    return dummyheadnode->next;
}
int main()
{
    linkedlist ll1, ll2, ll3;

    ll1.InsertAtTail(1);
    ll1.InsertAtTail(3);
    ll1.InsertAtTail(5);
    ll1.InsertAtTail(8);
    ll1.display();

    ll2.InsertAtTail(2);
    ll2.InsertAtTail(4);
    ll2.InsertAtTail(7);
    ll2.InsertAtTail(9);
    ll2.display();

    ll3.head = mergeLinkedLists(ll1.head, ll2.head);
    ll3.display();

    return 0;
}