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

void deleteAtPosition(Node* &head,int pos){
    int curr_pos = 0;
    Node* prev = head;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }
    //prev pointing to node at pos-1
    Node* temp = prev->next;
    prev->next = prev->next->next;
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
    insertAtHead(head, 1);
    display(head);

    insertAtHead(head, 2);
    display(head);

    insertAtHead(head, 3);
    display(head); 
    insertAtHead(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    
    deleteAtPosition(head,3);
    display(head);
    return 0;
}
