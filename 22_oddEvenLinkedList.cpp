#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void InsertAtTail(int data){
        Node* new_node = new Node(data);
        if(head==NULL){
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
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
Node* oddEvenLinkedList(Node* &head){

    if(!head){
        return head;
    }

    Node* evenHead=head->next;
    Node* oddPtr = head;
    Node* evenPtr = evenHead;

    while(evenPtr && evenPtr->next){
        oddPtr->next = oddPtr->next->next;
        evenPtr->next = evenPtr->next->next;

        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
    }
    oddPtr->next = evenHead;
    return head;
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

    ll.head = oddEvenLinkedList(ll.head);
    ll.Display();
    return 0;
}


