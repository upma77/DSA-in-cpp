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
Node *rotateByK(Node* &head,int k){
    //1.find length of ll;
    int n = 0;
    //2.find tail node
    Node * tail = head;
    while(tail->next!=NULL){
        n++;
        tail=tail->next;//finding last node
    }
    n++;
    k=k%n;
    if(k==0){
        return head;
    }
    tail->next = head;
    //3.traverse n-k nodes
    Node* temp = head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }
    //temp is now pointing to (n-k)th node
    Node* newhead = temp->next;
    temp->next=NULL;
    return newhead;
}
int main(){
    linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    
    ll.display();

    ll.head = rotateByK(ll.head,9);
    ll.display();

    return 0 ;
}