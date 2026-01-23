#include <iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
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

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
Node *mergeLinkedList(Node *&head1, Node *&head2)
{
    Node *dummyNode = new Node(-1);
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *ptr3 = dummyNode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->val < ptr2->val)
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
    if (ptr1==NULL) 
    {
        ptr3->next = ptr2;
    }
    else
    {
        ptr3->next = ptr1;
    }
    return dummyNode->next;
}
Node * mergeKLinkedList(vector <Node*> &lists){
    if(lists.size()==0){
        return NULL;
    }
    while(lists.size()>1){
        Node * mergedHead = mergeLinkedList(lists[0],lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}
int main(){
    LinkedList ll1,ll2,ll3;
    ll1.InsertAtTail(1);
    ll1.InsertAtTail(4);
    ll1.InsertAtTail(5);
    ll1.Display();

    ll2.InsertAtTail(2);
    ll2.InsertAtTail(3);
    ll2.InsertAtTail(8);
    ll2.Display();
    
    ll3.InsertAtTail(6);
    ll3.InsertAtTail(7);
    ll3.InsertAtTail(9);
    ll2.Display();

    vector<Node*>lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);

    LinkedList mergedLL;
    mergedLL.head=mergeKLinkedList(lists);
    mergedLL.Display();
}