#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void deleteAtEnd(Node* &head){
    Node* second_Last = head;
    while(second_Last->next->next!=NULL){
        second_Last=second_Last->next;
    }
    Node* temp = second_Last->next;
    second_Last->next = NULL;
    free(temp);
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    insertAtHead(head, 2);
    display(head);

    insertAtHead(head, 1);
    display(head);

    insertAtHead(head, 3);
    display(head); 

    deleteAtEnd(head);
    display(head);

    return 0;
}
