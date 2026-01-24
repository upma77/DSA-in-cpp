#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node * next;

    Node(int data){
        val = data;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node * head;
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
Node * findMiddleNode(Node * &head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.Display();

    Node* middleNode = findMiddleNode(ll.head);
    cout<<middleNode->val<<endl;

    return 0;

}