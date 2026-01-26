#include<iostream>
using namespace std;

class Node{
    public:

    int val;
    Node* next;

    Node (int data){
    val = data;
    next = NULL;
    }
};

class linkedlist{
    public:
    Node* head;
        
    linkedlist(){
        head=NULL;
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

    void display(){
        Node * temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }    
};
bool isPalindrome(Node* head){
    //find middle element
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }  
    //now slow is pointing to middle element
    //break the linked list in the list
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;
    //3.reverse the second half of linked list
    while(curr!=NULL){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextNode;
    }
    //4.check if the two linkedlists are equal
    Node* head1 = head;
    Node* head2 = prev;

    while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
int main(){
    linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(3);
    ll.InsertAtTail(2);
    ll.InsertAtTail(1);
    
    ll.display();

    cout<<isPalindrome(ll.head)<<endl;

    return 0;

}