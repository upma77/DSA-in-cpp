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

void insertAtEnd(Node* &head, int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtEnd(head,2);
    display(head);
    insertAtEnd(head,1);
    display(head);
    insertAtEnd(head,4);
    display(head);

    return 0;

}