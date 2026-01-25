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
    LinkedList(){
        head = NULL;
    }
    void InsertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

    void Display(){
        Node * temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    } 
};
bool detectCycle(Node * head){
    Node * slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if (slow == fast){
            cout<<"both pointer meet at : ";
            cout<<slow->val<<endl;
            return true;
        }
    }
    return false;
}
int main(){

LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.InsertAtTail(7);
    
    ll.Display();

    ll.head->next->next->next->next->next->next->next = ll.head->next->next;
    cout<<detectCycle(ll.head)<<endl;
    return 0;
}